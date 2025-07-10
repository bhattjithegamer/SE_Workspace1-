# Agar.io Clone

A browser-based clone of the popular Agar.io game with multiplayer simulation and leaderboard features.

## Features

### ✅ Completed Features
- **Leaderboard**: Real-time leaderboard displayed in the bottom-right corner showing top 10 players
- **Multiplayer Simulation**: 8 AI players with different names and behaviors
- **Player Movement**: Mouse-controlled movement with smooth following
- **Food System**: Randomly generated colored food items that increase player size
- **Split Mechanism**: Press spacebar to split your cell (when large enough)
- **Zoom System**: Camera automatically zooms based on player size
- **Grid Background**: Visual grid for better spatial awareness
- **Score Tracking**: Real-time score and mass display
- **Responsive Design**: Fullscreen canvas that adapts to window size

### 🎮 Game Controls
- **Mouse**: Move your cell by moving the cursor
- **Spacebar**: Split your cell (only works when you're large enough)
- **Start Button**: Begin the game after entering your name
- **Stop Button**: Pause the game
- **Restart Button**: Reload the page to restart

### 🏆 Leaderboard Features
- Shows top 10 players by score
- Displays medals (🥇🥈🥉) for top 3 positions
- Highlights your position with "(You)" label and green background
- Updates in real-time as scores change
- Shows both human player and AI bot scores

### 🤖 AI Players
- 8 AI players with unique names: Bot Alpha, Bot Beta, Bot Gamma, etc.
- Each AI has different colors and starting sizes
- AI players move around the map and eat food
- AI players compete on the leaderboard with the human player

### 🎯 Game Mechanics
- Eat food to grow larger and increase your score
- Larger players move slightly slower
- Camera zooms out as you grow larger
- Split functionality allows strategic gameplay
- 10,000 x 10,000 game world size

## How to Play

1. Open `index.html` in a web browser
2. Enter your name in the input field
3. Click "Start" to begin playing
4. Move your mouse to control your cell
5. Eat the colored food dots to grow larger
6. Try to get to the top of the leaderboard!
7. Use spacebar to split when you're large enough for strategic plays

## Installation

Simply open the `index.html` file in any modern web browser. No additional installation or dependencies required!

## Technical Details

- Built with vanilla HTML5, CSS3, and JavaScript
- Uses Canvas API for rendering
- Responsive design that works on different screen sizes
- Smooth 60 FPS gameplay with requestAnimationFrame
- Real-time leaderboard updates

## Browser Compatibility

Compatible with all modern browsers including:
- Chrome
- Firefox
- Safari
- Edge

Enjoy playing your Agar.io clone! 🎮