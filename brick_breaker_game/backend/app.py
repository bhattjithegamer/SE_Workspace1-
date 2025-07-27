from flask import Flask, request, jsonify, render_template
from flask_cors import CORS
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
import os
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

app = Flask(__name__)
app.config['SECRET_KEY'] = os.getenv('SECRET_KEY', 'your-secret-key-here')
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///brick_breaker.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# Enable CORS for frontend
CORS(app)

# Initialize database
db = SQLAlchemy(app)

# Database Models
class Score(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    player = db.Column(db.String(100), nullable=False)
    score = db.Column(db.Integer, nullable=False)
    level = db.Column(db.Integer, nullable=False)
    date_created = db.Column(db.DateTime, default=datetime.utcnow)
    
    def to_dict(self):
        return {
            'id': self.id,
            'player': self.player,
            'score': self.score,
            'level': self.level,
            'date_created': self.date_created.isoformat()
        }

class GameSettings(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    setting_name = db.Column(db.String(100), unique=True, nullable=False)
    setting_value = db.Column(db.String(500), nullable=False)
    date_updated = db.Column(db.DateTime, default=datetime.utcnow, onupdate=datetime.utcnow)

# Routes
@app.route('/')
def index():
    """Serve the main game page"""
    return render_template('index.html')

@app.route('/api/scores', methods=['GET'])
def get_scores():
    """Get top scores for leaderboard"""
    try:
        scores = Score.query.order_by(Score.score.desc()).limit(10).all()
        return jsonify([score.to_dict() for score in scores])
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/scores', methods=['POST'])
def add_score():
    """Add a new score"""
    try:
        data = request.get_json()
        
        if not data or 'score' not in data or 'player' not in data:
            return jsonify({'error': 'Missing required fields'}), 400
        
        new_score = Score(
            player=data['player'],
            score=data['score'],
            level=data.get('level', 1)
        )
        
        db.session.add(new_score)
        db.session.commit()
        
        return jsonify(new_score.to_dict()), 201
    except Exception as e:
        db.session.rollback()
        return jsonify({'error': str(e)}), 500

@app.route('/api/scores/<int:player_id>', methods=['GET'])
def get_player_scores(player_id):
    """Get scores for a specific player"""
    try:
        scores = Score.query.filter_by(id=player_id).order_by(Score.date_created.desc()).all()
        return jsonify([score.to_dict() for score in scores])
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/scores/top/<int:limit>', methods=['GET'])
def get_top_scores(limit):
    """Get top N scores"""
    try:
        if limit > 100:  # Prevent too many results
            limit = 100
        scores = Score.query.order_by(Score.score.desc()).limit(limit).all()
        return jsonify([score.to_dict() for score in scores])
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/stats', methods=['GET'])
def get_game_stats():
    """Get game statistics"""
    try:
        total_scores = Score.query.count()
        avg_score = db.session.query(db.func.avg(Score.score)).scalar() or 0
        max_score = db.session.query(db.func.max(Score.score)).scalar() or 0
        total_players = db.session.query(db.func.count(db.func.distinct(Score.player))).scalar() or 0
        
        return jsonify({
            'total_scores': total_scores,
            'average_score': round(float(avg_score), 2),
            'highest_score': max_score,
            'unique_players': total_players
        })
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/settings', methods=['GET'])
def get_settings():
    """Get game settings"""
    try:
        settings = GameSettings.query.all()
        return jsonify({setting.setting_name: setting.setting_value for setting in settings})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/settings', methods=['POST'])
def update_settings():
    """Update game settings"""
    try:
        data = request.get_json()
        
        for setting_name, setting_value in data.items():
            setting = GameSettings.query.filter_by(setting_name=setting_name).first()
            if setting:
                setting.setting_value = str(setting_value)
            else:
                setting = GameSettings(setting_name=setting_name, setting_value=str(setting_value))
                db.session.add(setting)
        
        db.session.commit()
        return jsonify({'message': 'Settings updated successfully'})
    except Exception as e:
        db.session.rollback()
        return jsonify({'error': str(e)}), 500

@app.route('/api/health', methods=['GET'])
def health_check():
    """Health check endpoint"""
    return jsonify({'status': 'healthy', 'timestamp': datetime.utcnow().isoformat()})

# Error handlers
@app.errorhandler(404)
def not_found(error):
    return jsonify({'error': 'Resource not found'}), 404

@app.errorhandler(500)
def internal_error(error):
    db.session.rollback()
    return jsonify({'error': 'Internal server error'}), 500

# Database initialization
def init_db():
    """Initialize the database with tables"""
    with app.app_context():
        db.create_all()
        
        # Add default settings if they don't exist
        default_settings = {
            'ball_speed': '5',
            'paddle_speed': '8',
            'power_up_chance': '0.1',
            'max_lives': '3',
            'brick_rows': '8',
            'brick_cols': '12'
        }
        
        for setting_name, setting_value in default_settings.items():
            if not GameSettings.query.filter_by(setting_name=setting_name).first():
                setting = GameSettings(setting_name=setting_name, setting_value=setting_value)
                db.session.add(setting)
        
        db.session.commit()

if __name__ == '__main__':
    init_db()
    app.run(debug=True, host='0.0.0.0', port=5000)