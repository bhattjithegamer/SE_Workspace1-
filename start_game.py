#!/usr/bin/env python3
"""
🎮 Enhanced Agar.io Game Launcher
A beautiful Agar.io clone with authentication and stunning visuals!
"""

import os
import sys
import time
import subprocess
from threading import Timer
import webbrowser

def print_banner():
    """Print a beautiful banner"""
    banner = """
╔═══════════════════════════════════════════════════════════════╗
║                    🎮 ENHANCED AGAR.IO GAME 🎮                ║
║                                                               ║
║              Beautiful • Animated • Full-Featured            ║
╚═══════════════════════════════════════════════════════════════╝
    """
    print("\033[96m" + banner + "\033[0m")  # Cyan color

def print_features():
    """Print game features"""
    features = """
✨ FEATURES:
   🎯 Enhanced gameplay with AI opponents
   🎨 Beautiful animated UI with glow effects  
   🔐 User authentication system
   🏆 Real-time leaderboard
   📱 Responsive design
   🤖 Intelligent AI players
   🗺️  Mini-map navigation
   💾 Score persistence
   
🎮 CONTROLS:
   🖱️  Mouse: Move your cell
   ⌨️  Space: Split cell
   🎯 Goal: Eat food and smaller players!
"""
    print("\033[92m" + features + "\033[0m")  # Green color

def print_credentials():
    """Print test credentials"""
    creds = """
🔑 TEST CREDENTIALS:
   Username: admin
   Password: admin123
   
   Or create your own account! 🆕
"""
    print("\033[93m" + creds + "\033[0m")  # Yellow color

def check_dependencies():
    """Check if required dependencies are installed"""
    try:
        import flask
        print("✅ Flask is installed")
        return True
    except ImportError:
        print("❌ Flask not found! Installing dependencies...")
        try:
            subprocess.check_call([sys.executable, '-m', 'pip', 'install', '-r', 'requirements.txt'])
            print("✅ Dependencies installed successfully!")
            return True
        except subprocess.CalledProcessError:
            print("❌ Failed to install dependencies. Please run:")
            print("   pip install -r requirements.txt")
            return False

def open_browser():
    """Open the browser after a delay"""
    print("🌐 Opening browser...")
    webbrowser.open('http://localhost:5000')

def main():
    """Main launcher function"""
    print_banner()
    print_features()
    print_credentials()
    
    print("🔧 Checking dependencies...")
    if not check_dependencies():
        return
    
    print("🚀 Starting the Enhanced Agar.io Game Server...")
    print("📍 Server will start at: http://localhost:5000")
    print("⏱️  Browser will open automatically in 3 seconds...")
    print("\n" + "="*60)
    print("🎮 ENJOY THE GAME! Press Ctrl+C to stop the server")
    print("="*60 + "\n")
    
    # Set up browser opening timer
    Timer(3.0, open_browser).start()
    
    # Start the Flask application
    try:
        os.environ['FLASK_ENV'] = 'development'
        from app import app
        app.run(debug=True, host='0.0.0.0', port=5000)
    except KeyboardInterrupt:
        print("\n🛑 Server stopped. Thanks for playing!")
    except Exception as e:
        print(f"❌ Error starting server: {e}")
        print("💡 Try running: python app.py")

if __name__ == "__main__":
    main()