#!/bin/bash

# Brick Breaker Game Setup Script
# This script sets up the complete Brick Breaker game project

echo "🚀 Setting up Brick Breaker Game..."
echo "=================================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if Python is installed
check_python() {
    print_status "Checking Python installation..."
    if command -v python3 &> /dev/null; then
        PYTHON_VERSION=$(python3 --version)
        print_success "Python found: $PYTHON_VERSION"
    else
        print_error "Python 3 is not installed. Please install Python 3.8 or higher."
        exit 1
    fi
}

# Check if Node.js is installed
check_node() {
    print_status "Checking Node.js installation..."
    if command -v node &> /dev/null; then
        NODE_VERSION=$(node --version)
        print_success "Node.js found: $NODE_VERSION"
    else
        print_error "Node.js is not installed. Please install Node.js 16 or higher."
        exit 1
    fi
}

# Setup Python backend
setup_backend() {
    print_status "Setting up Python backend..."
    cd backend
    
    # Create virtual environment
    if [ ! -d "venv" ]; then
        print_status "Creating virtual environment..."
        python3 -m venv venv
    fi
    
    # Activate virtual environment
    source venv/bin/activate
    
    # Install dependencies
    print_status "Installing Python dependencies..."
    pip install -r requirements.txt
    
    # Create .env file if it doesn't exist
    if [ ! -f ".env" ]; then
        print_status "Creating .env file..."
        cp .env.example .env
        print_warning "Please update the .env file with your configuration."
    fi
    
    # Initialize database
    print_status "Initializing database..."
    python app.py &
    BACKEND_PID=$!
    sleep 3
    kill $BACKEND_PID 2>/dev/null
    
    print_success "Backend setup complete!"
    cd ..
}

# Setup mobile app
setup_mobile() {
    print_status "Setting up React Native mobile app..."
    cd mobile
    
    # Install dependencies
    print_status "Installing Node.js dependencies..."
    npm install
    
    # iOS setup (macOS only)
    if [[ "$OSTYPE" == "darwin"* ]]; then
        print_status "Setting up iOS dependencies..."
        cd ios && pod install && cd ..
    else
        print_warning "iOS setup skipped (macOS required for iOS development)"
    fi
    
    print_success "Mobile app setup complete!"
    cd ..
}

# Create start scripts
create_scripts() {
    print_status "Creating start scripts..."
    
    # Backend start script
    cat > start_backend.sh << 'EOF'
#!/bin/bash
cd backend
source venv/bin/activate
python app.py
EOF
    chmod +x start_backend.sh
    
    # Frontend start script
    cat > start_frontend.sh << 'EOF'
#!/bin/bash
cd frontend
python3 -m http.server 8000
EOF
    chmod +x start_frontend.sh
    
    # Mobile start script
    cat > start_mobile.sh << 'EOF'
#!/bin/bash
cd mobile
npm start
EOF
    chmod +x start_mobile.sh
    
    print_success "Start scripts created!"
}

# Create documentation
create_docs() {
    print_status "Creating documentation..."
    
    cat > QUICK_START.md << 'EOF'
# Quick Start Guide

## Prerequisites
- Python 3.8+
- Node.js 16+
- Git

## Quick Setup
1. Run the setup script: `./setup.sh`
2. Start the backend: `./start_backend.sh`
3. Start the frontend: `./start_frontend.sh`
4. Open http://localhost:8000 in your browser

## Mobile Development
1. Start Metro bundler: `./start_mobile.sh`
2. Run on Android: `cd mobile && npx react-native run-android`
3. Run on iOS: `cd mobile && npx react-native run-ios`

## Game Controls
- **Desktop**: Mouse/Arrow keys to move paddle, Spacebar to launch ball
- **Mobile**: Touch and drag to move paddle, tap to launch ball

## Features
- Classic brick breaker gameplay
- Multiple levels with increasing difficulty
- Power-ups and special effects
- Score tracking and leaderboards
- Responsive design for mobile and desktop
- Python backend for data persistence
- Mobile app with React Native

## Project Structure
```
brick_breaker_game/
├── frontend/           # Web game (HTML, CSS, JS)
├── backend/            # Python Flask server
├── mobile/             # Mobile app (React Native)
├── assets/             # Game assets (images, sounds)
└── docs/              # Documentation
```
EOF
    
    print_success "Documentation created!"
}

# Main setup function
main() {
    print_status "Starting Brick Breaker Game setup..."
    
    # Check prerequisites
    check_python
    check_node
    
    # Setup components
    setup_backend
    setup_mobile
    
    # Create scripts and docs
    create_scripts
    create_docs
    
    echo ""
    echo "🎉 Setup complete!"
    echo "=================="
    echo ""
    echo "Next steps:"
    echo "1. Start the backend: ./start_backend.sh"
    echo "2. Start the frontend: ./start_frontend.sh"
    echo "3. Open http://localhost:8000 in your browser"
    echo ""
    echo "For mobile development:"
    echo "1. Start Metro bundler: ./start_mobile.sh"
    echo "2. Run on Android: cd mobile && npx react-native run-android"
    echo "3. Run on iOS: cd mobile && npx react-native run-ios"
    echo ""
    echo "For more information, see QUICK_START.md"
}

# Run main function
main