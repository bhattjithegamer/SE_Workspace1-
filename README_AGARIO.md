# 🎮 Enhanced Agar.io Game with Authentication

A beautiful, feature-rich Agar.io clone with user authentication, Python Flask backend, and stunning visual effects.

## ✨ Features

### 🎯 Game Features
- **Real-time multiplayer-style gameplay** with AI opponents
- **Beautiful animated UI** with glowing effects and particle animations
- **Enhanced visual effects** including glow effects, shadows, and smooth animations
- **Intelligent AI players** with strategic behavior
- **Mini-map** for better navigation
- **Camera system** with smooth following
- **Cell splitting** mechanism (Space key)
- **Real-time leaderboard** with live updates
- **Score persistence** with backend integration

### 🔐 Authentication System
- **Beautiful login page** with animated background and floating particles
- **User registration** and login functionality
- **Secure password hashing** using Werkzeug
- **Session management** with Flask sessions
- **Score tracking** for each user
- **User dashboard** with statistics

### 🎨 Visual Enhancements
- **Animated search input** with rotating borders and glow effects
- **Gradient backgrounds** and modern UI design
- **Particle animations** and floating elements
- **Responsive design** that works on different screen sizes
- **Smooth transitions** and hover effects
- **Neon-style color scheme** with cyan highlights

## 🚀 Quick Start

### Prerequisites
- Python 3.7 or higher
- pip (Python package installer)

### Installation

1. **Clone or download the project files**

2. **Install dependencies**
   ```bash
   pip install -r requirements.txt
   ```

3. **Run the application**
   ```bash
   python app.py
   ```

4. **Open your browser and navigate to**
   ```
   http://localhost:5000
   ```

## 🎮 How to Play

### 🔑 Login/Registration
1. **Access the login page** at `http://localhost:5000`
2. **Create a new account** by clicking "Sign Up" or use test credentials:
   - Username: `admin`
   - Password: `admin123`
3. **Login** to access the game

### 🎯 Game Controls
- **Mouse movement**: Control your cell direction
- **Space key**: Split your cell (when large enough)
- **Animated name input**: Enter your display name in the beautiful search-style input
- **Start button**: Begin the game
- **Stop button**: Pause the game
- **Restart button**: Reset the game

### 🏆 Gameplay
- **Eat food particles** (colored dots) to grow larger
- **Avoid larger players** that can absorb you
- **Hunt smaller players** when you're big enough
- **Use splitting strategically** to catch prey or escape predators
- **Monitor the mini-map** for spatial awareness
- **Track your progress** on the live leaderboard

## 🛠️ Technical Details

### 🗂️ Project Structure
```
├── app.py                 # Flask backend application
├── requirements.txt       # Python dependencies
├── game_users.db         # SQLite database (auto-created)
├── templates/
│   ├── login.html        # Beautiful login page
│   └── game.html         # Enhanced game interface
└── static/               # Static files (optional)
```

### 🗃️ Database Schema
```sql
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    password_hash TEXT NOT NULL,
    email TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    high_score INTEGER DEFAULT 0
);
```

### 🔌 API Endpoints
- `POST /api/login` - User authentication
- `POST /api/register` - User registration
- `POST /api/save_score` - Save game score
- `GET /api/user_info` - Get user information
- `GET /logout` - Logout user

## 🎨 Visual Features

### 🌟 Animated Login Page
- **Gradient background** with moving grid animation
- **Floating particles** with random movements
- **Glowing title** with text shadow effects
- **Form hover effects** with scaling and shadows
- **Button animations** with shimmer effects
- **Real-time form validation** with error/success messages

### 🎮 Enhanced Game Interface
- **Animated search input** for player name with rotating gradient borders
- **Glow effects** on player cells and larger AI players
- **Particle food** with HSL color generation
- **Smooth camera movement** following the player
- **Mini-map** showing all players and viewport
- **Modern UI panels** with transparency and neon borders
- **Real-time statistics** display

### 🤖 AI Features
- **8 unique AI players** with emoji names and distinct colors
- **Intelligent targeting** system for food and smaller players
- **Aggressive behavior** patterns based on size
- **Strategic movement** with pathfinding
- **Dynamic difficulty** that scales with player size

## 🔧 Customization

### 🎨 Styling
You can customize the visual appearance by modifying the CSS in:
- `templates/login.html` - Login page styles
- `templates/game.html` - Game interface styles

### 🎮 Game Parameters
Adjust game settings in `templates/game.html`:
```javascript
const gameWidth = 10000;     // World width
const gameHeight = 10000;    // World height
const gridSize = 100;        // Grid spacing
```

### 🤖 AI Behavior
Modify AI intelligence in the `updateAIPlayers()` function:
- Change targeting distance
- Adjust aggressiveness
- Modify movement patterns

## 🔒 Security Features

- **Password hashing** using Werkzeug's secure methods
- **Session management** with secure cookies
- **SQL injection protection** with parameterized queries
- **Input validation** on both client and server sides
- **CSRF protection** through proper session handling

## 🚀 Deployment Tips

### 🖥️ Local Development
- Default runs on `http://localhost:5000`
- Debug mode enabled for development
- SQLite database for easy setup

### 🌐 Production Deployment
1. **Disable debug mode** in `app.py`
2. **Change secret key** to a secure random value
3. **Use production database** (PostgreSQL, MySQL)
4. **Add SSL certificate** for HTTPS
5. **Use production WSGI server** (Gunicorn, uWSGI)

## 🎯 Game Features Explained

### 🔄 Ball Visibility Fix
The original issue with ball visibility has been resolved through:
- **Proper camera system** that follows the player
- **Correct coordinate transformation** from world to screen space
- **Enhanced rendering** with glow effects making the player more visible
- **Improved contrast** with neon colors against dark background

### 🎨 Attractive Visual Elements
- **Gradient backgrounds** and neon color schemes
- **Particle animations** and floating elements
- **Smooth transitions** and hover effects
- **Glow effects** on game elements
- **Modern UI design** with glassmorphism effects

## 🎮 Test Credentials

**Default Admin Account:**
- Username: `admin`
- Password: `admin123`

## 🐛 Troubleshooting

### Common Issues:
1. **Port already in use**: Change port in `app.py` 
2. **Database errors**: Delete `game_users.db` to reset
3. **Dependencies issues**: Update pip and reinstall requirements
4. **Browser compatibility**: Use modern browsers (Chrome, Firefox, Safari)

## 📝 Future Enhancements

- **Real multiplayer** with WebSocket support
- **Power-ups** and special abilities
- **Tournament mode** with brackets
- **Mobile app** version
- **Social features** (friends, clans)
- **Custom skins** and themes
- **Advanced AI** with machine learning

## 🤝 Contributing

Feel free to contribute by:
- Adding new visual effects
- Improving AI behavior
- Adding new game modes
- Enhancing security features
- Optimizing performance

## 📄 License

This project is open source and available under the MIT License.

---

**Enjoy playing the enhanced Agar.io game! 🎮✨**