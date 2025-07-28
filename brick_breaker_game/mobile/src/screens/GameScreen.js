import React, { useState, useRef } from 'react';
import {
  View,
  Text,
  StyleSheet,
  Dimensions,
  StatusBar,
  TouchableOpacity,
  Alert,
} from 'react-native';
import { WebView } from 'react-native-webview';
import Icon from 'react-native-vector-icons/MaterialIcons';
import LinearGradient from 'react-native-linear-gradient';

const { width, height } = Dimensions.get('window');

const GameScreen = ({ navigation }) => {
  const [gameState, setGameState] = useState('loading');
  const [score, setScore] = useState(0);
  const [lives, setLives] = useState(3);
  const [level, setLevel] = useState(1);
  const webViewRef = useRef(null);

  // HTML content for the game
  const gameHTML = `
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
        <title>Brick Breaker Mobile</title>
        <style>
            * {
                margin: 0;
                padding: 0;
                box-sizing: border-box;
            }
            
            body {
                font-family: 'Courier New', monospace;
                background: linear-gradient(135deg, #0c0c0c 0%, #1a1a2e 50%, #16213e 100%);
                color: #ffffff;
                overflow: hidden;
                touch-action: none;
            }
            
            #gameCanvas {
                display: block;
                margin: 0 auto;
                border: 2px solid #00d4ff;
                background: #000;
                box-shadow: 0 0 20px rgba(0, 212, 255, 0.4);
            }
            
            .game-ui {
                position: fixed;
                top: 10px;
                left: 10px;
                right: 10px;
                z-index: 100;
                display: flex;
                justify-content: space-between;
                align-items: center;
                padding: 10px;
                background: rgba(0, 0, 0, 0.7);
                border-radius: 10px;
                border: 1px solid #00d4ff;
            }
            
            .stat {
                text-align: center;
                color: #00d4ff;
                font-weight: bold;
            }
            
            .stat-label {
                font-size: 12px;
                color: #888;
            }
            
            .stat-value {
                font-size: 16px;
            }
            
            .back-button {
                position: fixed;
                top: 20px;
                right: 20px;
                z-index: 200;
                background: rgba(0, 0, 0, 0.8);
                border: 1px solid #00d4ff;
                border-radius: 25px;
                width: 50px;
                height: 50px;
                display: flex;
                align-items: center;
                justify-content: center;
                color: #00d4ff;
                font-size: 24px;
                cursor: pointer;
            }
        </style>
    </head>
    <body>
        <div class="game-ui">
            <div class="stat">
                <div class="stat-label">SCORE</div>
                <div class="stat-value" id="score">0</div>
            </div>
            <div class="stat">
                <div class="stat-label">LEVEL</div>
                <div class="stat-value" id="level">1</div>
            </div>
            <div class="stat">
                <div class="stat-label">LIVES</div>
                <div class="stat-value" id="lives">3</div>
            </div>
        </div>
        
        <canvas id="gameCanvas" width="${width - 40}" height="${height - 120}"></canvas>
        
        <script>
            // Mobile-optimized Brick Breaker Game
            class MobileBrickBreaker {
                constructor() {
                    this.canvas = document.getElementById('gameCanvas');
                    this.ctx = this.canvas.getContext('2d');
                    this.width = this.canvas.width;
                    this.height = this.canvas.height;
                    
                    // Game state
                    this.gameState = 'menu';
                    this.score = 0;
                    this.level = 1;
                    this.lives = 3;
                    this.isPaused = false;
                    
                    // Game objects
                    this.paddle = null;
                    this.balls = [];
                    this.bricks = [];
                    this.powerUps = [];
                    this.particles = [];
                    
                    // Touch handling
                    this.touchX = 0;
                    this.isTouching = false;
                    
                    // Game settings
                    this.paddleWidth = Math.min(100, this.width * 0.2);
                    this.paddleHeight = 15;
                    this.ballRadius = 8;
                    this.brickRows = 6;
                    this.brickCols = Math.floor(this.width / 70);
                    this.brickWidth = (this.width - 20) / this.brickCols - 5;
                    this.brickHeight = 20;
                    
                    this.init();
                }
                
                init() {
                    this.setupTouchEvents();
                    this.createPaddle();
                    this.createBall();
                    this.createBricks();
                    this.gameLoop();
                }
                
                setupTouchEvents() {
                    this.canvas.addEventListener('touchstart', (e) => {
                        e.preventDefault();
                        this.isTouching = true;
                        this.touchX = e.touches[0].clientX;
                        
                        if (this.gameState === 'menu') {
                            this.startGame();
                        } else if (this.gameState === 'playing') {
                            this.launchBall();
                        }
                    });
                    
                    this.canvas.addEventListener('touchmove', (e) => {
                        e.preventDefault();
                        this.touchX = e.touches[0].clientX;
                    });
                    
                    this.canvas.addEventListener('touchend', (e) => {
                        e.preventDefault();
                        this.isTouching = false;
                    });
                }
                
                createPaddle() {
                    this.paddle = {
                        x: this.width / 2 - this.paddleWidth / 2,
                        y: this.height - 50,
                        width: this.paddleWidth,
                        height: this.paddleHeight,
                        color: '#00d4ff'
                    };
                }
                
                createBall() {
                    this.balls = [{
                        x: this.width / 2,
                        y: this.height - 60,
                        radius: this.ballRadius,
                        dx: 0,
                        dy: 0,
                        speed: 5,
                        color: '#ff6b6b',
                        isLaunched: false
                    }];
                }
                
                createBricks() {
                    this.bricks = [];
                    const colors = ['#ff6b6b', '#4ecdc4', '#45b7d1', '#96ceb4', '#feca57', '#ff9ff3'];
                    
                    for (let row = 0; row < this.brickRows; row++) {
                        for (let col = 0; col < this.brickCols; col++) {
                            const brick = {
                                x: col * (this.brickWidth + 5) + 10,
                                y: row * (this.brickHeight + 5) + 50,
                                width: this.brickWidth,
                                height: this.brickHeight,
                                color: colors[row % colors.length],
                                visible: true
                            };
                            this.bricks.push(brick);
                        }
                    }
                }
                
                startGame() {
                    this.gameState = 'playing';
                    this.score = 0;
                    this.level = 1;
                    this.lives = 3;
                    this.updateUI();
                }
                
                update() {
                    if (this.gameState !== 'playing' || this.isPaused) return;
                    
                    this.updatePaddle();
                    this.updateBalls();
                    this.checkCollisions();
                    this.checkLevelComplete();
                }
                
                updatePaddle() {
                    if (this.isTouching) {
                        const rect = this.canvas.getBoundingClientRect();
                        this.paddle.x = this.touchX - rect.left - this.paddle.width / 2;
                    }
                    
                    this.paddle.x = Math.max(0, Math.min(this.width - this.paddle.width, this.paddle.x));
                }
                
                updateBalls() {
                    this.balls.forEach((ball, index) => {
                        if (!ball.isLaunched) {
                            ball.x = this.paddle.x + this.paddle.width / 2;
                            ball.y = this.paddle.y - ball.radius;
                            return;
                        }
                        
                        ball.x += ball.dx;
                        ball.y += ball.dy;
                        
                        // Wall collisions
                        if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= this.width) {
                            ball.dx = -ball.dx;
                        }
                        
                        if (ball.y - ball.radius <= 0) {
                            ball.dy = -ball.dy;
                        }
                        
                        // Ball out of bounds
                        if (ball.y - ball.radius > this.height) {
                            this.balls.splice(index, 1);
                            if (this.balls.length === 0) {
                                this.lives--;
                                this.updateUI();
                                
                                if (this.lives <= 0) {
                                    this.gameOver();
                                } else {
                                    this.createBall();
                                }
                            }
                        }
                    });
                }
                
                checkCollisions() {
                    this.balls.forEach(ball => {
                        // Paddle collision
                        if (this.checkBallPaddleCollision(ball)) {
                            this.handlePaddleCollision(ball);
                        }
                        
                        // Brick collisions
                        this.bricks.forEach(brick => {
                            if (brick.visible && this.checkBallBrickCollision(ball, brick)) {
                                this.handleBrickCollision(ball, brick);
                            }
                        });
                    });
                }
                
                checkBallPaddleCollision(ball) {
                    return ball.x + ball.radius > this.paddle.x &&
                           ball.x - ball.radius < this.paddle.x + this.paddle.width &&
                           ball.y + ball.radius > this.paddle.y &&
                           ball.y - ball.radius < this.paddle.y + this.paddle.height;
                }
                
                checkBallBrickCollision(ball, brick) {
                    return ball.x + ball.radius > brick.x &&
                           ball.x - ball.radius < brick.x + brick.width &&
                           ball.y + ball.radius > brick.y &&
                           ball.y - ball.radius < brick.y + brick.height;
                }
                
                handlePaddleCollision(ball) {
                    ball.dy = -Math.abs(ball.dy);
                    
                    const hitPos = (ball.x - this.paddle.x) / this.paddle.width;
                    const angle = (hitPos - 0.5) * Math.PI / 3;
                    ball.dx = Math.sin(angle) * ball.speed;
                    ball.dy = -Math.cos(angle) * ball.speed;
                }
                
                handleBrickCollision(ball, brick) {
                    const ballCenterX = ball.x;
                    const ballCenterY = ball.y;
                    const brickCenterX = brick.x + brick.width / 2;
                    const brickCenterY = brick.y + brick.height / 2;
                    
                    const dx = ballCenterX - brickCenterX;
                    const dy = ballCenterY - brickCenterY;
                    
                    if (Math.abs(dx) > Math.abs(dy)) {
                        ball.dx = -ball.dx;
                    } else {
                        ball.dy = -ball.dy;
                    }
                    
                    brick.visible = false;
                    this.score += 10;
                    this.updateUI();
                }
                
                checkLevelComplete() {
                    const visibleBricks = this.bricks.filter(brick => brick.visible);
                    if (visibleBricks.length === 0) {
                        this.levelComplete();
                    }
                }
                
                levelComplete() {
                    this.level++;
                    this.createBricks();
                    this.createBall();
                    this.paddle.x = this.width / 2 - this.paddleWidth / 2;
                    this.updateUI();
                }
                
                gameOver() {
                    this.gameState = 'gameOver';
                    // Send score to React Native
                    window.ReactNativeWebView.postMessage(JSON.stringify({
                        type: 'gameOver',
                        score: this.score,
                        level: this.level
                    }));
                }
                
                launchBall() {
                    this.balls.forEach(ball => {
                        if (!ball.isLaunched) {
                            ball.isLaunched = true;
                            ball.dx = (Math.random() - 0.5) * 4;
                            ball.dy = -ball.speed;
                        }
                    });
                }
                
                updateUI() {
                    document.getElementById('score').textContent = this.score;
                    document.getElementById('level').textContent = this.level;
                    document.getElementById('lives').textContent = this.lives;
                }
                
                render() {
                    // Clear canvas
                    this.ctx.fillStyle = '#000000';
                    this.ctx.fillRect(0, 0, this.width, this.height);
                    
                    // Draw paddle
                    this.ctx.fillStyle = this.paddle.color;
                    this.ctx.fillRect(this.paddle.x, this.paddle.y, this.paddle.width, this.paddle.height);
                    
                    // Draw balls
                    this.balls.forEach(ball => {
                        this.ctx.fillStyle = ball.color;
                        this.ctx.beginPath();
                        this.ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
                        this.ctx.fill();
                    });
                    
                    // Draw bricks
                    this.bricks.forEach(brick => {
                        if (brick.visible) {
                            this.ctx.fillStyle = brick.color;
                            this.ctx.fillRect(brick.x, brick.y, brick.width, brick.height);
                            
                            this.ctx.strokeStyle = '#ffffff';
                            this.ctx.lineWidth = 1;
                            this.ctx.strokeRect(brick.x, brick.y, brick.width, brick.height);
                        }
                    });
                }
                
                gameLoop() {
                    this.update();
                    this.render();
                    requestAnimationFrame(() => this.gameLoop());
                }
            }
            
            // Initialize game
            const game = new MobileBrickBreaker();
        </script>
    </body>
    </html>
  `;

  const handleMessage = (event) => {
    try {
      const data = JSON.parse(event.nativeEvent.data);
      if (data.type === 'gameOver') {
        setScore(data.score);
        setLevel(data.level);
        setLives(0);
        
        Alert.alert(
          'Game Over!',
          `Final Score: ${data.score}\nLevel Reached: ${data.level}`,
          [
            {
              text: 'Play Again',
              onPress: () => {
                webViewRef.current?.reload();
                setScore(0);
                setLives(3);
                setLevel(1);
              },
            },
            {
              text: 'Back to Menu',
              onPress: () => navigation.goBack(),
            },
          ]
        );
      }
    } catch (error) {
      console.log('Error parsing message:', error);
    }
  };

  return (
    <View style={styles.container}>
      <StatusBar barStyle="light-content" backgroundColor="#0c0c0c" />
      
      <TouchableOpacity
        style={styles.backButton}
        onPress={() => navigation.goBack()}
      >
        <Icon name="arrow-back" size={24} color="#00d4ff" />
      </TouchableOpacity>

      <WebView
        ref={webViewRef}
        source={{ html: gameHTML }}
        style={styles.webview}
        onMessage={handleMessage}
        javaScriptEnabled={true}
        domStorageEnabled={true}
        startInLoadingState={true}
        scalesPageToFit={false}
        scrollEnabled={false}
        bounces={false}
        showsHorizontalScrollIndicator={false}
        showsVerticalScrollIndicator={false}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#0c0c0c',
  },
  webview: {
    flex: 1,
  },
  backButton: {
    position: 'absolute',
    top: 50,
    right: 20,
    zIndex: 1000,
    backgroundColor: 'rgba(0, 0, 0, 0.8)',
    borderWidth: 1,
    borderColor: '#00d4ff',
    borderRadius: 25,
    width: 50,
    height: 50,
    alignItems: 'center',
    justifyContent: 'center',
  },
});

export default GameScreen;