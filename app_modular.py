from flask import Flask
from config import config
from models import db
from routes import register_routes
import os

def create_app(config_name='default'):
    """Application factory pattern"""
    app = Flask(__name__)
    
    # Load configuration
    app.config.from_object(config[config_name])
    
    # Initialize extensions
    db.init_app(app)
    
    # Register routes
    register_routes(app)
    
    # Create tables
    with app.app_context():
        db.create_all()
    
    return app

if __name__ == '__main__':
    # Get environment or default to development
    env = os.environ.get('FLASK_ENV', 'development')
    app = create_app(env)
    app.run(debug=True)