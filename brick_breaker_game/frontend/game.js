// Brick Breaker Game - Main Game Logic
class BrickBreakerGame {
    constructor() {
        this.canvas = document.getElementById('gameCanvas');
        this.ctx = this.canvas.getContext('2d');
        this.backendUrl = 'http://localhost:5000';
        
        // Game state
        this.gameState = 'menu'; // menu, playing, paused, gameOver
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
        
        // Game settings
        this.canvasWidth = 800;
        this.canvasHeight = 600;
        this.paddleWidth = 100;
        this.paddleHeight = 15;
        this.ballRadius = 8;
        this.brickRows = 8;
        this.brickCols = 12;
        this.brickWidth = 60;
        this.brickHeight = 20;
        this.brickPadding = 5;
        
        // Physics
        this.ballSpeed = 5;
        this.paddleSpeed = 8;
        
        // Power-up settings
        this.powerUpTypes = ['speed', 'slow', 'wide', 'narrow', 'multi'];
        this.powerUpChance = 0.1; // 10% chance when brick breaks
        
        // Input handling
        this.keys = {};
        this.mouseX = 0;
        this.isMouseDown = false;
        
        this.init();
    }
    
    init() {
        this.setupCanvas();
        this.setupEventListeners();
        this.createPaddle();
        this.createBall();
        this.createBricks();
        this.loadLeaderboard();
        this.gameLoop();
    }
    
    setupCanvas() {
        // Handle canvas scaling for different screen sizes
        const rect = this.canvas.getBoundingClientRect();
        const scaleX = this.canvas.width / rect.width;
        const scaleY = this.canvas.height / rect.height;
        
        this.canvas.addEventListener('mousemove', (e) => {
            const rect = this.canvas.getBoundingClientRect();
            this.mouseX = (e.clientX - rect.left) * scaleX;
        });
        
        this.canvas.addEventListener('mousedown', () => {
            this.isMouseDown = true;
            if (this.gameState === 'menu') {
                this.startGame();
            } else if (this.gameState === 'playing') {
                this.launchBall();
            }
        });
        
        this.canvas.addEventListener('mouseup', () => {
            this.isMouseDown = false;
        });
    }
    
    setupEventListeners() {
        // Keyboard controls
        document.addEventListener('keydown', (e) => {
            this.keys[e.key] = true;
            
            if (e.key === ' ' && this.gameState === 'menu') {
                this.startGame();
            } else if (e.key === ' ' && this.gameState === 'playing') {
                this.launchBall();
            } else if (e.key === 'p' || e.key === 'P') {
                this.togglePause();
            }
        });
        
        document.addEventListener('keyup', (e) => {
            this.keys[e.key] = false;
        });
        
        // Touch controls for mobile
        this.canvas.addEventListener('touchstart', (e) => {
            e.preventDefault();
            const touch = e.touches[0];
            const rect = this.canvas.getBoundingClientRect();
            this.mouseX = (touch.clientX - rect.left) * (this.canvas.width / rect.width);
            this.isMouseDown = true;
            
            if (this.gameState === 'menu') {
                this.startGame();
            } else if (this.gameState === 'playing') {
                this.launchBall();
            }
        });
        
        this.canvas.addEventListener('touchmove', (e) => {
            e.preventDefault();
            const touch = e.touches[0];
            const rect = this.canvas.getBoundingClientRect();
            this.mouseX = (touch.clientX - rect.left) * (this.canvas.width / rect.width);
        });
        
        this.canvas.addEventListener('touchend', (e) => {
            e.preventDefault();
            this.isMouseDown = false;
        });
        
        // Button event listeners
        document.getElementById('startButton').addEventListener('click', () => {
            this.startGame();
        });
        
        document.getElementById('pauseButton').addEventListener('click', () => {
            this.togglePause();
        });
    }
    
    createPaddle() {
        this.paddle = {
            x: this.canvasWidth / 2 - this.paddleWidth / 2,
            y: this.canvasHeight - 50,
            width: this.paddleWidth,
            height: this.paddleHeight,
            speed: this.paddleSpeed,
            color: '#00d4ff'
        };
    }
    
    createBall() {
        this.balls = [{
            x: this.canvasWidth / 2,
            y: this.canvasHeight - 60,
            radius: this.ballRadius,
            dx: 0,
            dy: 0,
            speed: this.ballSpeed,
            color: '#ff6b6b',
            isLaunched: false
        }];
    }
    
    createBricks() {
        this.bricks = [];
        const colors = ['#ff6b6b', '#4ecdc4', '#45b7d1', '#96ceb4', '#feca57', '#ff9ff3', '#54a0ff', '#5f27cd'];
        
        for (let row = 0; row < this.brickRows; row++) {
            for (let col = 0; col < this.brickCols; col++) {
                const brick = {
                    x: col * (this.brickWidth + this.brickPadding) + this.brickPadding,
                    y: row * (this.brickHeight + this.brickPadding) + this.brickPadding + 50,
                    width: this.brickWidth,
                    height: this.brickHeight,
                    color: colors[row % colors.length],
                    visible: true,
                    health: 1 + Math.floor(row / 2), // Higher rows have more health
                    maxHealth: 1 + Math.floor(row / 2)
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
        this.isPaused = false;
        
        this.createPaddle();
        this.createBall();
        this.createBricks();
        this.powerUps = [];
        this.particles = [];
        
        this.updateUI();
        this.hideOverlay();
    }
    
    togglePause() {
        if (this.gameState === 'playing') {
            this.isPaused = !this.isPaused;
            if (this.isPaused) {
                this.showOverlay('PAUSED', 'Press P to resume', 'pauseButton');
            } else {
                this.hideOverlay();
            }
        }
    }
    
    gameOver() {
        this.gameState = 'gameOver';
        this.showOverlay('GAME OVER', `Final Score: ${this.score}`, 'startButton');
        this.saveScore();
        this.playSound('gameOverSound');
    }
    
    levelComplete() {
        this.level++;
        this.ballSpeed += 0.5;
        this.createBricks();
        this.createBall();
        this.paddle.x = this.canvasWidth / 2 - this.paddleWidth / 2;
        this.updateUI();
        
        // Show level complete message
        this.showOverlay(`LEVEL ${this.level - 1} COMPLETE!`, `Score: ${this.score}`, 'startButton');
        setTimeout(() => {
            if (this.gameState === 'playing') {
                this.hideOverlay();
            }
        }, 2000);
    }
    
    update() {
        if (this.gameState !== 'playing' || this.isPaused) return;
        
        this.updatePaddle();
        this.updateBalls();
        this.updatePowerUps();
        this.updateParticles();
        this.checkCollisions();
        this.checkLevelComplete();
    }
    
    updatePaddle() {
        // Mouse/touch control
        if (this.mouseX > 0) {
            this.paddle.x = this.mouseX - this.paddle.width / 2;
        }
        
        // Keyboard control
        if (this.keys['ArrowLeft'] || this.keys['a'] || this.keys['A']) {
            this.paddle.x -= this.paddle.speed;
        }
        if (this.keys['ArrowRight'] || this.keys['d'] || this.keys['D']) {
            this.paddle.x += this.paddle.speed;
        }
        
        // Keep paddle within canvas bounds
        this.paddle.x = Math.max(0, Math.min(this.canvasWidth - this.paddle.width, this.paddle.x));
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
            if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= this.canvasWidth) {
                ball.dx = -ball.dx;
                this.playSound('hitSound');
            }
            
            if (ball.y - ball.radius <= 0) {
                ball.dy = -ball.dy;
                this.playSound('hitSound');
            }
            
            // Ball out of bounds
            if (ball.y - ball.radius > this.canvasHeight) {
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
    
    updatePowerUps() {
        this.powerUps.forEach((powerUp, index) => {
            powerUp.y += powerUp.speed;
            
            // Remove power-ups that fall off screen
            if (powerUp.y > this.canvasHeight) {
                this.powerUps.splice(index, 1);
            }
        });
    }
    
    updateParticles() {
        this.particles.forEach((particle, index) => {
            particle.x += particle.dx;
            particle.y += particle.dy;
            particle.life--;
            
            if (particle.life <= 0) {
                this.particles.splice(index, 1);
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
            
            // Power-up collisions
            this.powerUps.forEach((powerUp, index) => {
                if (this.checkPowerUpCollision(powerUp)) {
                    this.activatePowerUp(powerUp);
                    this.powerUps.splice(index, 1);
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
    
    checkPowerUpCollision(powerUp) {
        return this.paddle.x < powerUp.x + powerUp.width &&
               this.paddle.x + this.paddle.width > powerUp.x &&
               this.paddle.y < powerUp.y + powerUp.height &&
               this.paddle.y + this.paddle.height > powerUp.y;
    }
    
    handlePaddleCollision(ball) {
        ball.dy = -Math.abs(ball.dy);
        
        // Calculate bounce angle based on where ball hits paddle
        const hitPos = (ball.x - this.paddle.x) / this.paddle.width;
        const angle = (hitPos - 0.5) * Math.PI / 3; // -30 to 30 degrees
        ball.dx = Math.sin(angle) * ball.speed;
        ball.dy = -Math.cos(angle) * ball.speed;
        
        this.playSound('hitSound');
    }
    
    handleBrickCollision(ball, brick) {
        // Determine collision side and bounce accordingly
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
        
        brick.health--;
        if (brick.health <= 0) {
            brick.visible = false;
            this.score += 10 * brick.maxHealth;
            this.updateUI();
            this.playSound('breakSound');
            this.createParticles(brick.x + brick.width / 2, brick.y + brick.height / 2, brick.color);
            
            // Chance to spawn power-up
            if (Math.random() < this.powerUpChance) {
                this.spawnPowerUp(brick.x + brick.width / 2, brick.y + brick.height / 2);
            }
        }
    }
    
    activatePowerUp(powerUp) {
        this.playSound('powerUpSound');
        
        switch (powerUp.type) {
            case 'speed':
                this.balls.forEach(ball => {
                    ball.speed *= 1.5;
                    ball.dx *= 1.5;
                    ball.dy *= 1.5;
                });
                setTimeout(() => {
                    this.balls.forEach(ball => {
                        ball.speed /= 1.5;
                        ball.dx /= 1.5;
                        ball.dy /= 1.5;
                    });
                }, 10000);
                break;
                
            case 'slow':
                this.balls.forEach(ball => {
                    ball.speed *= 0.7;
                    ball.dx *= 0.7;
                    ball.dy *= 0.7;
                });
                setTimeout(() => {
                    this.balls.forEach(ball => {
                        ball.speed /= 0.7;
                        ball.dx /= 0.7;
                        ball.dy /= 0.7;
                    });
                }, 10000);
                break;
                
            case 'wide':
                this.paddle.width *= 1.5;
                setTimeout(() => {
                    this.paddle.width /= 1.5;
                }, 15000);
                break;
                
            case 'narrow':
                this.paddle.width *= 0.7;
                setTimeout(() => {
                    this.paddle.width /= 0.7;
                }, 15000);
                break;
                
            case 'multi':
                const newBalls = [];
                this.balls.forEach(ball => {
                    newBalls.push({
                        ...ball,
                        dx: ball.dx + (Math.random() - 0.5) * 2,
                        dy: ball.dy + (Math.random() - 0.5) * 2
                    });
                });
                this.balls.push(...newBalls);
                break;
        }
    }
    
    spawnPowerUp(x, y) {
        const type = this.powerUpTypes[Math.floor(Math.random() * this.powerUpTypes.length)];
        const powerUp = {
            x: x - 15,
            y: y,
            width: 30,
            height: 30,
            type: type,
            speed: 2,
            color: this.getPowerUpColor(type)
        };
        this.powerUps.push(powerUp);
    }
    
    getPowerUpColor(type) {
        const colors = {
            speed: '#ff6b6b',
            slow: '#4ecdc4',
            wide: '#45b7d1',
            narrow: '#96ceb4',
            multi: '#feca57'
        };
        return colors[type] || '#ffffff';
    }
    
    createParticles(x, y, color) {
        for (let i = 0; i < 8; i++) {
            this.particles.push({
                x: x,
                y: y,
                dx: (Math.random() - 0.5) * 8,
                dy: (Math.random() - 0.5) * 8,
                life: 30,
                color: color
            });
        }
    }
    
    checkLevelComplete() {
        const visibleBricks = this.bricks.filter(brick => brick.visible);
        if (visibleBricks.length === 0) {
            this.levelComplete();
        }
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
    
    render() {
        // Clear canvas
        this.ctx.fillStyle = '#000000';
        this.ctx.fillRect(0, 0, this.canvasWidth, this.canvasHeight);
        
        // Draw background grid
        this.drawBackground();
        
        // Draw game objects
        this.drawPaddle();
        this.drawBalls();
        this.drawBricks();
        this.drawPowerUps();
        this.drawParticles();
        
        // Draw UI elements
        this.drawUI();
    }
    
    drawBackground() {
        this.ctx.strokeStyle = 'rgba(0, 212, 255, 0.1)';
        this.ctx.lineWidth = 1;
        
        // Vertical lines
        for (let x = 0; x < this.canvasWidth; x += 50) {
            this.ctx.beginPath();
            this.ctx.moveTo(x, 0);
            this.ctx.lineTo(x, this.canvasHeight);
            this.ctx.stroke();
        }
        
        // Horizontal lines
        for (let y = 0; y < this.canvasHeight; y += 50) {
            this.ctx.beginPath();
            this.ctx.moveTo(0, y);
            this.ctx.lineTo(this.canvasWidth, y);
            this.ctx.stroke();
        }
    }
    
    drawPaddle() {
        this.ctx.fillStyle = this.paddle.color;
        this.ctx.fillRect(this.paddle.x, this.paddle.y, this.paddle.width, this.paddle.height);
        
        // Add glow effect
        this.ctx.shadowColor = this.paddle.color;
        this.ctx.shadowBlur = 10;
        this.ctx.fillRect(this.paddle.x, this.paddle.y, this.paddle.width, this.paddle.height);
        this.ctx.shadowBlur = 0;
    }
    
    drawBalls() {
        this.balls.forEach(ball => {
            this.ctx.fillStyle = ball.color;
            this.ctx.beginPath();
            this.ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
            this.ctx.fill();
            
            // Add glow effect
            this.ctx.shadowColor = ball.color;
            this.ctx.shadowBlur = 8;
            this.ctx.beginPath();
            this.ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
            this.ctx.fill();
            this.ctx.shadowBlur = 0;
        });
    }
    
    drawBricks() {
        this.bricks.forEach(brick => {
            if (brick.visible) {
                // Calculate color intensity based on health
                const intensity = brick.health / brick.maxHealth;
                const color = this.adjustColorIntensity(brick.color, intensity);
                
                this.ctx.fillStyle = color;
                this.ctx.fillRect(brick.x, brick.y, brick.width, brick.height);
                
                // Add border
                this.ctx.strokeStyle = '#ffffff';
                this.ctx.lineWidth = 1;
                this.ctx.strokeRect(brick.x, brick.y, brick.width, brick.height);
            }
        });
    }
    
    drawPowerUps() {
        this.powerUps.forEach(powerUp => {
            this.ctx.fillStyle = powerUp.color;
            this.ctx.fillRect(powerUp.x, powerUp.y, powerUp.width, powerUp.height);
            
            // Add icon
            this.ctx.fillStyle = '#ffffff';
            this.ctx.font = '16px Arial';
            this.ctx.textAlign = 'center';
            this.ctx.fillText(this.getPowerUpIcon(powerUp.type), 
                            powerUp.x + powerUp.width / 2, 
                            powerUp.y + powerUp.height / 2 + 5);
        });
    }
    
    drawParticles() {
        this.particles.forEach(particle => {
            const alpha = particle.life / 30;
            this.ctx.fillStyle = `rgba(255, 255, 255, ${alpha})`;
            this.ctx.beginPath();
            this.ctx.arc(particle.x, particle.y, 2, 0, Math.PI * 2);
            this.ctx.fill();
        });
    }
    
    drawUI() {
        // Draw level indicator
        this.ctx.fillStyle = '#00d4ff';
        this.ctx.font = '20px Orbitron';
        this.ctx.textAlign = 'center';
        this.ctx.fillText(`Level ${this.level}`, this.canvasWidth / 2, 30);
    }
    
    getPowerUpIcon(type) {
        const icons = {
            speed: '⚡',
            slow: '🐌',
            wide: '📏',
            narrow: '📐',
            multi: '🔮'
        };
        return icons[type] || '?';
    }
    
    adjustColorIntensity(color, intensity) {
        // Simple color intensity adjustment
        const r = parseInt(color.slice(1, 3), 16);
        const g = parseInt(color.slice(3, 5), 16);
        const b = parseInt(color.slice(5, 7), 16);
        
        const newR = Math.floor(r * intensity);
        const newG = Math.floor(g * intensity);
        const newB = Math.floor(b * intensity);
        
        return `rgb(${newR}, ${newG}, ${newB})`;
    }
    
    updateUI() {
        document.getElementById('score').textContent = this.score;
        document.getElementById('level').textContent = this.level;
        document.getElementById('lives').textContent = this.lives;
    }
    
    showOverlay(title, message, buttonId) {
        document.getElementById('overlayTitle').textContent = title;
        document.getElementById('overlayMessage').textContent = message;
        document.getElementById('gameOverlay').style.display = 'flex';
        
        // Show/hide appropriate button
        document.getElementById('startButton').style.display = buttonId === 'startButton' ? 'block' : 'none';
        document.getElementById('pauseButton').style.display = buttonId === 'pauseButton' ? 'block' : 'none';
    }
    
    hideOverlay() {
        document.getElementById('gameOverlay').style.display = 'none';
    }
    
    playSound(soundId) {
        const sound = document.getElementById(soundId);
        if (sound) {
            sound.currentTime = 0;
            sound.play().catch(e => console.log('Audio play failed:', e));
        }
    }
    
    async saveScore() {
        try {
            const response = await fetch(`${this.backendUrl}/api/scores`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    score: this.score,
                    level: this.level,
                    player: 'Player' // In a real app, you'd get the player name
                })
            });
            
            if (response.ok) {
                this.loadLeaderboard();
            }
        } catch (error) {
            console.error('Failed to save score:', error);
        }
    }
    
    async loadLeaderboard() {
        try {
            const response = await fetch(`${this.backendUrl}/api/scores`);
            const scores = await response.json();
            
            const leaderboardElement = document.getElementById('leaderboard');
            leaderboardElement.innerHTML = '';
            
            scores.slice(0, 10).forEach((score, index) => {
                const item = document.createElement('div');
                item.className = 'leaderboard-item';
                item.innerHTML = `
                    <span>${index + 1}. ${score.player}</span>
                    <span>${score.score}</span>
                `;
                leaderboardElement.appendChild(item);
            });
        } catch (error) {
            console.error('Failed to load leaderboard:', error);
            document.getElementById('leaderboard').innerHTML = '<div class="loading">Failed to load leaderboard</div>';
        }
    }
    
    gameLoop() {
        this.update();
        this.render();
        requestAnimationFrame(() => this.gameLoop());
    }
}

// Initialize game when page loads
document.addEventListener('DOMContentLoaded', () => {
    new BrickBreakerGame();
});