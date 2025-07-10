THIS SHOULD BE A LINTER ERRORfrom flask import Flask, render_template, request, jsonify, session, redirect, url_for
from werkzeug.security import generate_password_hash, check_password_hash
import sqlite3
import os
from datetime import datetime

app = Flask(__name__)
app.secret_key = 'your-secret-key-here'  # Change this to a random secret key

def init_db():
    """Initialize the database with users table"""
    conn = sqlite3.connect('game_users.db')
    cursor = conn.cursor()
    
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password_hash TEXT NOT NULL,
            email TEXT,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            high_score INTEGER DEFAULT 0
        )
    ''')
    
    # Create a default admin user for testing
    admin_hash = generate_password_hash('admin123')
    cursor.execute('''
        INSERT OR IGNORE INTO users (username, password_hash, email, high_score)
        VALUES (?, ?, ?, ?)
    ''', ('admin', admin_hash, 'admin@agario.com', 1000))
    
    conn.commit()
    conn.close()

@app.route('/')
def index():
    """Main page - redirect to login if not authenticated"""
    if 'user_id' in session:
        return render_template('game.html', username=session.get('username'))
    return redirect(url_for('login'))

@app.route('/login')
def login():
    """Login page"""
    return render_template('login.html')

@app.route('/api/login', methods=['POST'])
def api_login():
    """Handle login API request"""
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    
    if not username or not password:
        return jsonify({'success': False, 'message': 'Username and password required'})
    
    conn = sqlite3.connect('game_users.db')
    cursor = conn.cursor()
    
    cursor.execute('SELECT id, username, password_hash FROM users WHERE username = ?', (username,))
    user = cursor.fetchone()
    conn.close()
    
    if user and check_password_hash(user[2], password):
        session['user_id'] = user[0]
        session['username'] = user[1]
        return jsonify({
            'success': True, 
            'message': 'Login successful',
            'user_id': user[0],
            'username': user[1]
        })
    else:
        return jsonify({'success': False, 'message': 'Invalid username or password'})

@app.route('/api/register', methods=['POST'])
def api_register():
    """Handle registration API request"""
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    email = data.get('email', '')
    
    if not username or not password:
        return jsonify({'success': False, 'message': 'Username and password required'})
    
    conn = sqlite3.connect('game_users.db')
    cursor = conn.cursor()
    
    # Check if username already exists
    cursor.execute('SELECT id FROM users WHERE username = ?', (username,))
    if cursor.fetchone():
        conn.close()
        return jsonify({'success': False, 'message': 'Username already exists'})
    
    # Create new user
    password_hash = generate_password_hash(password)
    try:
        cursor.execute('''
            INSERT INTO users (username, password_hash, email)
            VALUES (?, ?, ?)
        ''', (username, password_hash, email))
        conn.commit()
        user_id = cursor.lastrowid
        conn.close()
        
        session['user_id'] = user_id
        session['username'] = username
        
        return jsonify({
            'success': True, 
            'message': 'Registration successful',
            'user_id': user_id,
            'username': username
        })
    except Exception as e:
        conn.close()
        return jsonify({'success': False, 'message': 'Registration failed'})

@app.route('/api/save_score', methods=['POST'])
def save_score():
    """Save user's high score"""
    if 'user_id' not in session:
        return jsonify({'success': False, 'message': 'Not authenticated'})
    
    data = request.get_json()
    score = data.get('score', 0)
    user_id = session['user_id']
    
    conn = sqlite3.connect('game_users.db')
    cursor = conn.cursor()
    
    # Update high score if current score is higher
    cursor.execute('''
        UPDATE users SET high_score = MAX(high_score, ?) 
        WHERE id = ?
    ''', (score, user_id))
    
    conn.commit()
    conn.close()
    
    return jsonify({'success': True, 'message': 'Score saved'})

@app.route('/logout')
def logout():
    """Logout user"""
    session.clear()
    return redirect(url_for('login'))

@app.route('/api/user_info')
def user_info():
    """Get current user information"""
    if 'user_id' not in session:
        return jsonify({'success': False, 'message': 'Not authenticated'})
    
    conn = sqlite3.connect('game_users.db')
    cursor = conn.cursor()
    
    cursor.execute('''
        SELECT id, username, email, high_score, created_at 
        FROM users WHERE id = ?
    ''', (session['user_id'],))
    
    user = cursor.fetchone()
    conn.close()
    
    if user:
        return jsonify({
            'success': True,
            'user': {
                'id': user[0],
                'username': user[1],
                'email': user[2],
                'high_score': user[3],
                'created_at': user[4]
            }
        })
    else:
        return jsonify({'success': False, 'message': 'User not found'})

if __name__ == '__main__':
    init_db()
    app.run(debug=True, host='0.0.0.0', port=5000)