# 🎮 Brick Breaker Game

A complete, modern Brick Breaker game with web frontend, Python backend, and React Native mobile app.

![Brick Breaker Game](https://img.shields.io/badge/Game-Brick%20Breaker-blue)
![Python](https://img.shields.io/badge/Python-3.8+-green)
![React Native](https://img.shields.io/badge/React%20Native-0.72+-blue)
![HTML5](https://img.shields.io/badge/HTML5-Canvas-orange)
![CSS3](https://img.shields.io/badge/CSS3-Responsive-pink)

## 🚀 Features

### Game Features
- **Classic Brick Breaker Gameplay** - Break bricks with a bouncing ball
- **Multiple Levels** - Increasing difficulty with each level
- **Power-ups System** - Speed up, slow down, wide paddle, narrow paddle, multi-ball
- **Particle Effects** - Visual feedback when bricks break
- **Sound Effects** - Immersive audio experience
- **Responsive Design** - Works on desktop, tablet, and mobile

### Technical Features
- **Web Frontend** - HTML5 Canvas, CSS3, JavaScript (ES6+)
- **Python Backend** - Flask API with SQLite database
- **Mobile App** - React Native with WebView integration
- **Real-time Leaderboard** - Global score tracking
- **Cross-platform** - Desktop, Android, and iOS support

## 📁 Project Structure

```
brick_breaker_game/
├── frontend/                 # Web game (HTML, CSS, JS)
│   ├── index.html           # Main game page
│   ├── styles.css           # Game styling
│   └── game.js              # Game logic
├── backend/                  # Python Flask server
│   ├── app.py               # Main Flask application
│   ├── requirements.txt     # Python dependencies
│   └── .env.example         # Environment configuration
├── mobile/                   # React Native mobile app
│   ├── src/
│   │   ├── App.js           # Main app component
│   │   └── screens/         # App screens
│   ├── package.json         # Node.js dependencies
│   └── metro.config.js      # Metro bundler config
├── assets/                   # Game assets
│   └── sounds/              # Audio files
├── setup.sh                 # Automated setup script
├── start_backend.sh         # Backend start script
├── start_frontend.sh        # Frontend start script
├── start_mobile.sh          # Mobile start script
└── README.md               # This file
```

## 🛠️ Prerequisites

- **Python 3.8+** - For backend server
- **Node.js 16+** - For mobile app development
- **Git** - For version control
- **Android Studio** (optional) - For Android development
- **Xcode** (optional) - For iOS development (macOS only)

## ⚡ Quick Start

### 1. Clone and Setup
```bash
git clone <repository-url>
cd brick_breaker_game
./setup.sh
```

### 2. Start the Backend
```bash
./start_backend.sh
```
The backend will run on `http://localhost:5000`

### 3. Start the Frontend
```bash
./start_frontend.sh
```
The web game will be available at `http://localhost:8000`

### 4. Play the Game!
Open your browser and navigate to `http://localhost:8000`

## 📱 Mobile Development

### Android
```bash
cd mobile
npm start
# In another terminal:
npx react-native run-android
```

### iOS (macOS only)
```bash
cd mobile
npm start
# In another terminal:
npx react-native run-ios
```

## 🎮 Game Controls

### Desktop
- **Mouse/Arrow Keys** - Move paddle
- **Spacebar** - Launch ball
- **P** - Pause game

### Mobile
- **Touch & Drag** - Move paddle
- **Tap** - Launch ball
- **Back Button** - Return to menu

## 🎯 Game Features

### Power-ups
- ⚡ **Speed Up** - Increases ball speed
- 🐌 **Slow Down** - Decreases ball speed
- 📏 **Wide Paddle** - Makes paddle wider
- 📐 **Narrow Paddle** - Makes paddle narrower
- 🔮 **Multi Ball** - Creates multiple balls

### Scoring System
- **Brick Break** - 10 points per brick
- **Level Completion** - Bonus points
- **Power-up Collection** - Extra points
- **High Score Tracking** - Global leaderboard

## 🔧 API Endpoints

### Backend API (Flask)
- `GET /api/scores` - Get top scores
- `POST /api/scores` - Submit new score
- `GET /api/stats` - Get game statistics
- `GET /api/settings` - Get game settings
- `POST /api/settings` - Update game settings

## 🎨 Customization

### Adding Custom Sounds
1. Place audio files in `assets/sounds/`
2. Update `frontend/index.html` audio elements
3. Reference sounds in `frontend/game.js`

### Modifying Game Settings
1. Edit `backend/.env` file
2. Update game parameters in `frontend/game.js`
3. Restart the backend server

### Custom Themes
1. Modify CSS variables in `frontend/styles.css`
2. Update color schemes in `mobile/src/screens/`
3. Customize gradients and animations

## 🐛 Troubleshooting

### Common Issues

**Backend won't start:**
```bash
cd backend
source venv/bin/activate
pip install -r requirements.txt
python app.py
```

**Mobile app build fails:**
```bash
cd mobile
npm install
npx react-native start --reset-cache
```

**Game not loading:**
- Check browser console for errors
- Ensure backend is running on port 5000
- Verify CORS settings in backend

### Performance Tips
- Use hardware acceleration for better performance
- Optimize canvas rendering for mobile devices
- Minimize audio file sizes
- Use efficient collision detection algorithms

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙏 Acknowledgments

- HTML5 Canvas API for game rendering
- Flask framework for backend development
- React Native for mobile app development
- Open source community for inspiration

## 📞 Support

If you encounter any issues or have questions:
1. Check the troubleshooting section
2. Review the documentation
3. Open an issue on GitHub
4. Contact the development team

---

**Happy Gaming! 🎮✨**