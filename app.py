from flask import Flask, render_template, request, jsonify, session, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from werkzeug.security import generate_password_hash, check_password_hash
import secrets
import os

app = Flask(__name__)
app.config['SECRET_KEY'] = secrets.token_hex(16)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///agario.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

# User model
class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    password_hash = db.Column(db.String(120), nullable=False)
    high_score = db.Column(db.Integer, default=0)
    games_played = db.Column(db.Integer, default=0)

    def set_password(self, password):
        self.password_hash = generate_password_hash(password)

    def check_password(self, password):
        return check_password_hash(self.password_hash, password)

# Create tables
with app.app_context():
    db.create_all()

@app.route('/')
def index():
    if 'user_id' in session:
        return redirect(url_for('game'))
    return render_template('login.html')

@app.route('/login', methods=['POST'])
def login():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    
    user = User.query.filter_by(username=username).first()
    
    if user and user.check_password(password):
        session['user_id'] = user.id
        session['username'] = user.username
        return jsonify({
            'success': True, 
            'user_id': user.id,
            'username': user.username,
            'high_score': user.high_score,
            'games_played': user.games_played
        })
    else:
        return jsonify({'success': False, 'message': 'Invalid credentials'})

@app.route('/register', methods=['POST'])
def register():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    
    if User.query.filter_by(username=username).first():
        return jsonify({'success': False, 'message': 'Username already exists'})
    
    user = User(username=username)
    user.set_password(password)
    db.session.add(user)
    db.session.commit()
    
    session['user_id'] = user.id
    session['username'] = user.username
    
    return jsonify({
        'success': True,
        'user_id': user.id,
        'username': user.username,
        'high_score': 0,
        'games_played': 0
    })

@app.route('/game')
def game():
    if 'user_id' not in session:
        return redirect(url_for('index'))
    return render_template('game.html')

@app.route('/update_score', methods=['POST'])
def update_score():
    if 'user_id' not in session:
        return jsonify({'success': False, 'message': 'Not logged in'})
    
    data = request.get_json()
    score = data.get('score', 0)
    
    user = User.query.get(session['user_id'])
    if user:
        if score > user.high_score:
            user.high_score = score
        user.games_played += 1
        db.session.commit()
        
        return jsonify({'success': True, 'new_high_score': score > (user.high_score - score)})
    
    return jsonify({'success': False, 'message': 'User not found'})

@app.route('/logout')
def logout():
    session.clear()
    return redirect(url_for('index'))

@app.route('/leaderboard')
def leaderboard():
    top_players = User.query.order_by(User.high_score.desc()).limit(10).all()
    return jsonify([{
        'username': user.username,
        'high_score': user.high_score,
        'games_played': user.games_played
    } for user in top_players])

if __name__ == '__main__':
    app.run(debug=True)