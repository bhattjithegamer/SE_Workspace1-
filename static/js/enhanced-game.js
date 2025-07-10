const canvas = document.getElementById('gameCanvas');
const ctx = canvas.getContext('2d');
const miniCanvas = document.getElementById('miniCanvas');
const miniCtx = miniCanvas.getContext('2d');

const gameWidth = 10000;
const gameHeight = 10000;

let player = {
  x: gameWidth / 2,
  y: gameHeight / 2,
  radius: 25,
  color: '#00ffff',
  speed: 3,
  name: document.querySelector('.user-info') ? document.querySelector('.user-info').textContent.replace('🎮 Player: ', '') : 'Player',
  score: 0,
  isPlayer: true
};

let allPlayers = [];
let playerPieces = [player];
let food = [];
let mouseX = canvas.width / 2;
let mouseY = canvas.height / 2;

let gameRunning = false;
let gameLoopId = null;
let camera = { x: 0, y: 0 };

// Set the canvas to fullscreen
function setCanvasFullscreen() {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
}

setCanvasFullscreen();
window.addEventListener('resize', setCanvasFullscreen);

// Enhanced AI Players
function generateAIPlayers() {
  const aiNames = ['🤖 Alpha', '🔥 Beta', '⚡ Gamma', '💎 Delta', '🌟 Epsilon', '🎯 Zeta', '💫 Eta', '🌈 Theta'];
  const colors = ['#ff4757', '#2ed573', '#a55eea', '#ffa502', '#ff6b9d', '#26d0ce', '#ffdd59', '#8b4513'];
  
  for (let i = 0; i < 8; i++) {
    let aiPlayer = {
      x: Math.random() * (gameWidth - 200) + 100,
      y: Math.random() * (gameHeight - 200) + 100,
      radius: Math.random() * 35 + 20,
      color: colors[i],
      speed: Math.random() * 2.5 + 1.5,
      name: aiNames[i],
      score: Math.floor(Math.random() * 150),
      isPlayer: false,
      targetX: Math.random() * gameWidth,
      targetY: Math.random() * gameHeight,
      lastDirectionChange: 0,
      aggressiveness: Math.random()
    };
    allPlayers.push(aiPlayer);
  }
}

// Enhanced Grid Drawing
function drawGrid() {
  const gridSize = 100;
  ctx.strokeStyle = 'rgba(0, 255, 255, 0.1)';
  ctx.lineWidth = 1;

  const startX = Math.floor(camera.x / gridSize) * gridSize;
  const startY = Math.floor(camera.y / gridSize) * gridSize;
  const endX = camera.x + canvas.width;
  const endY = camera.y + canvas.height;

  for (let x = startX; x <= endX; x += gridSize) {
    ctx.beginPath();
    ctx.moveTo(x - camera.x, 0);
    ctx.lineTo(x - camera.x, canvas.height);
    ctx.stroke();
  }

  for (let y = startY; y <= endY; y += gridSize) {
    ctx.beginPath();
    ctx.moveTo(0, y - camera.y);
    ctx.lineTo(canvas.width, y - camera.y);
    ctx.stroke();
  }
}

// Enhanced Player Drawing with Glow Effects
function drawPlayer() {
  playerPieces.forEach(piece => {
    const screenX = piece.x - camera.x;
    const screenY = piece.y - camera.y;

    // Glow effect
    ctx.shadowColor = piece.color;
    ctx.shadowBlur = 20;
    
    // Main circle
    ctx.beginPath();
    ctx.arc(screenX, screenY, piece.radius, 0, Math.PI * 2);
    ctx.fillStyle = piece.color;
    ctx.fill();
    
    // Border
    ctx.shadowBlur = 0;
    ctx.strokeStyle = '#ffffff';
    ctx.lineWidth = 3;
    ctx.stroke();

    // Name
    if (piece.name) {
      ctx.fillStyle = '#ffffff';
      ctx.font = `bold ${Math.max(16, piece.radius / 2)}px Arial`;
      ctx.textAlign = 'center';
      ctx.textBaseline = 'middle';
      ctx.strokeStyle = '#000000';
      ctx.lineWidth = 2;
      ctx.strokeText(piece.name, screenX, screenY);
      ctx.fillText(piece.name, screenX, screenY);
    }
  });
}

// Enhanced AI Drawing
function drawAIPlayers() {
  allPlayers.forEach(aiPlayer => {
    const screenX = aiPlayer.x - camera.x;
    const screenY = aiPlayer.y - camera.y;

    // Only draw if on screen
    if (screenX > -aiPlayer.radius && screenX < canvas.width + aiPlayer.radius &&
        screenY > -aiPlayer.radius && screenY < canvas.height + aiPlayer.radius) {
      
      // Glow effect for larger players
      if (aiPlayer.radius > 30) {
        ctx.shadowColor = aiPlayer.color;
        ctx.shadowBlur = 15;
      }

      ctx.beginPath();
      ctx.arc(screenX, screenY, aiPlayer.radius, 0, Math.PI * 2);
      ctx.fillStyle = aiPlayer.color;
      ctx.fill();
      
      ctx.shadowBlur = 0;
      ctx.strokeStyle = '#ffffff';
      ctx.lineWidth = 2;
      ctx.stroke();

      // Name
      ctx.fillStyle = '#ffffff';
      ctx.font = `bold ${Math.max(12, aiPlayer.radius / 3)}px Arial`;
      ctx.textAlign = 'center';
      ctx.textBaseline = 'middle';
      ctx.strokeStyle = '#000000';
      ctx.lineWidth = 1;
      ctx.strokeText(aiPlayer.name, screenX, screenY);
      ctx.fillText(aiPlayer.name, screenX, screenY);
    }
  });
}

// Enhanced Food Drawing
function drawFood() {
  food.forEach((item) => {
    const screenX = item.x - camera.x;
    const screenY = item.y - camera.y;

    if (screenX > -item.radius && screenX < canvas.width + item.radius &&
        screenY > -item.radius && screenY < canvas.height + item.radius) {
      
      ctx.shadowColor = item.color;
      ctx.shadowBlur = 5;
      
      ctx.beginPath();
      ctx.arc(screenX, screenY, item.radius, 0, Math.PI * 2);
      ctx.fillStyle = item.color;
      ctx.fill();
      
      ctx.shadowBlur = 0;
    }
  });
}

// Camera System
function updateCamera() {
  const targetX = player.x - canvas.width / 2;
  const targetY = player.y - canvas.height / 2;
  
  camera.x += (targetX - camera.x) * 0.1;
  camera.y += (targetY - camera.y) * 0.1;
  
  // Keep camera within bounds
  camera.x = Math.max(0, Math.min(camera.x, gameWidth - canvas.width));
  camera.y = Math.max(0, Math.min(camera.y, gameHeight - canvas.height));
}

// Mini Map
function drawMiniMap() {
  miniCtx.clearRect(0, 0, 150, 150);
  
  // Background
  miniCtx.fillStyle = 'rgba(0, 20, 40, 0.8)';
  miniCtx.fillRect(0, 0, 150, 150);
  
  // Border
  miniCtx.strokeStyle = '#00ffff';
  miniCtx.lineWidth = 2;
  miniCtx.strokeRect(0, 0, 150, 150);
  
  const scaleX = 150 / gameWidth;
  const scaleY = 150 / gameHeight;
  
  // Player
  miniCtx.fillStyle = player.color;
  miniCtx.beginPath();
  miniCtx.arc(player.x * scaleX, player.y * scaleY, Math.max(2, player.radius * scaleX), 0, Math.PI * 2);
  miniCtx.fill();
  
  // AI Players
  allPlayers.forEach(ai => {
    miniCtx.fillStyle = ai.color;
    miniCtx.beginPath();
    miniCtx.arc(ai.x * scaleX, ai.y * scaleY, Math.max(1, ai.radius * scaleX), 0, Math.PI * 2);
    miniCtx.fill();
  });
  
  // Viewport indicator
  miniCtx.strokeStyle = '#ffffff';
  miniCtx.lineWidth = 1;
  miniCtx.strokeRect(camera.x * scaleX, camera.y * scaleY, canvas.width * scaleX, canvas.height * scaleY);
}

function clearCanvas() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
}

// Enhanced AI Behavior
function updateAIPlayers() {
  allPlayers.forEach(aiPlayer => {
    // More intelligent AI movement
    if (Date.now() - aiPlayer.lastDirectionChange > 3000) {
      // Look for nearby food or smaller players
      let closestTarget = null;
      let closestDistance = Infinity;
      
      // Check food
      food.forEach(item => {
        const distance = Math.sqrt(Math.pow(aiPlayer.x - item.x, 2) + Math.pow(aiPlayer.y - item.y, 2));
        if (distance < closestDistance && distance < 300) {
          closestTarget = item;
          closestDistance = distance;
        }
      });
      
      // Check smaller players
      [...allPlayers, ...playerPieces].forEach(otherPlayer => {
        if (otherPlayer !== aiPlayer && otherPlayer.radius < aiPlayer.radius * 0.8) {
          const distance = Math.sqrt(Math.pow(aiPlayer.x - otherPlayer.x, 2) + Math.pow(aiPlayer.y - otherPlayer.y, 2));
          if (distance < closestDistance && distance < 400) {
            closestTarget = otherPlayer;
            closestDistance = distance;
          }
        }
      });
      
      if (closestTarget) {
        aiPlayer.targetX = closestTarget.x;
        aiPlayer.targetY = closestTarget.y;
      } else {
        aiPlayer.targetX = Math.random() * gameWidth;
        aiPlayer.targetY = Math.random() * gameHeight;
      }
      
      aiPlayer.lastDirectionChange = Date.now();
    }

    let dx = aiPlayer.targetX - aiPlayer.x;
    let dy = aiPlayer.targetY - aiPlayer.y;
    let distance = Math.sqrt(dx * dx + dy * dy);

    if (distance > 15) {
      let moveX = (dx / distance) * aiPlayer.speed;
      let moveY = (dy / distance) * aiPlayer.speed;
      
      aiPlayer.x = Math.max(aiPlayer.radius, Math.min(aiPlayer.x + moveX, gameWidth - aiPlayer.radius));
      aiPlayer.y = Math.max(aiPlayer.radius, Math.min(aiPlayer.y + moveY, gameHeight - aiPlayer.radius));
    }

    // AI eats food
    food.forEach((item, index) => {
      let dx = aiPlayer.x - item.x;
      let dy = aiPlayer.y - item.y;
      let distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < aiPlayer.radius + item.radius) {
        food.splice(index, 1);
        aiPlayer.radius += item.radius / 8;
        aiPlayer.score += 2;
      }
    });
  });
}

// Enhanced Leaderboard
function updateLeaderboard() {
  let allPlayersData = [];
  
  if (player.name) {
    allPlayersData.push({
      name: player.name,
      score: player.score,
      isHuman: true
    });
  }
  
  allPlayers.forEach(aiPlayer => {
    allPlayersData.push({
      name: aiPlayer.name,
      score: aiPlayer.score,
      isHuman: false
    });
  });

  allPlayersData.sort((a, b) => b.score - a.score);

  const leaderboardContent = document.getElementById('leaderboardContent');
  leaderboardContent.innerHTML = '';

  allPlayersData.slice(0, 10).forEach((playerData, index) => {
    const entry = document.createElement('div');
    entry.className = 'leaderboard-entry';
    
    const rank = index + 1;
    const medal = rank === 1 ? '🥇' : rank === 2 ? '🥈' : rank === 3 ? '🥉' : `${rank}.`;
    
    entry.innerHTML = `
      <span class="player-name">${medal} ${playerData.name}${playerData.isHuman ? ' (You)' : ''}</span>
      <span class="player-score">${playerData.score}</span>
    `;
    
    if (playerData.isHuman) {
      entry.style.background = 'linear-gradient(90deg, rgba(0, 255, 255, 0.2), rgba(0, 255, 255, 0.1))';
      entry.style.borderRadius = '5px';
      entry.style.border = '1px solid rgba(0, 255, 255, 0.3)';
    }
    
    leaderboardContent.appendChild(entry);
  });
}

// Main Update Function
function update() {
  clearCanvas();
  updateCamera();

  drawGrid();
  drawFood();
  drawAIPlayers();
  drawPlayer();
  drawMiniMap();

  // Update game stats
  document.getElementById('scoreDisplay').textContent = player.score;
  document.getElementById('massDisplay').textContent = Math.floor(player.radius);
  document.getElementById('cellsDisplay').textContent = playerPieces.length;

  updateLeaderboard();

  // Check for collision with food (player)
  food.forEach((item, index) => {
    playerPieces.forEach(piece => {
      let dx = piece.x - item.x;
      let dy = piece.y - item.y;
      let distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < piece.radius + item.radius) {
        food.splice(index, 1);
        piece.radius += item.radius / 8;
        player.score += 2;
        
        // Save score to backend
        saveScore(player.score);
      }
    });
  });

  // Move player pieces toward mouse
  playerPieces.forEach(piece => {
    // Convert mouse position to world coordinates
    const worldMouseX = mouseX + camera.x;
    const worldMouseY = mouseY + camera.y;
    
    let dx = worldMouseX - piece.x;
    let dy = worldMouseY - piece.y;
    let distance = Math.sqrt(dx * dx + dy * dy);

    if (distance > 5) {
      let speed = Math.max(1, piece.speed - piece.radius / 50);
      let moveX = (dx / distance) * speed;
      let moveY = (dy / distance) * speed;

      piece.x = Math.max(piece.radius, Math.min(piece.x + moveX, gameWidth - piece.radius));
      piece.y = Math.max(piece.radius, Math.min(piece.y + moveY, gameHeight - piece.radius));
    }
  });

  updateAIPlayers();
}

// Enhanced Food Generation
function generateFood() {
  if (food.length < 2000) {
    for (let i = 0; i < 5; i++) {
      let foodX = Math.random() * gameWidth;
      let foodY = Math.random() * gameHeight;
      let foodRadius = Math.random() * 6 + 3;
      let hue = Math.random() * 360;
      let foodColor = `hsl(${hue}, 70%, 60%)`;
      food.push({ x: foodX, y: foodY, radius: foodRadius, color: foodColor });
    }
  }
}

// Enhanced Split Function
function splitPlayer() {
  if (playerPieces.length < 4 && player.radius > 25) {
    playerPieces.forEach((piece, index) => {
      if (piece.radius > 25) {
        const newRadius = piece.radius / 1.4;
        
        const worldMouseX = mouseX + camera.x;
        const worldMouseY = mouseY + camera.y;
        let angle = Math.atan2(worldMouseY - piece.y, worldMouseX - piece.x);
        
        const newPiece = {
          x: piece.x + newRadius * 2 * Math.cos(angle),
          y: piece.y + newRadius * 2 * Math.sin(angle),
          radius: newRadius,
          color: piece.color,
          speed: piece.speed + 1,
          name: piece.name,
          splitTime: Date.now()
        };
        
        piece.radius = newRadius;
        playerPieces.push(newPiece);
      }
    });
  }
}

function gameLoop() {
  if (gameRunning) {
    update();
    generateFood();
    gameLoopId = requestAnimationFrame(gameLoop);
  }
}

// Save score to backend
async function saveScore(score) {
  try {
    await fetch('/update_score', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ score: score })
    });
  } catch (error) {
    console.error('Failed to save score:', error);
  }
}

// Logout function
function logout() {
  window.location.href = '/logout';
}

// Event listeners
canvas.addEventListener('mousemove', function(event) {
  const rect = canvas.getBoundingClientRect();
  mouseX = event.clientX - rect.left;
  mouseY = event.clientY - rect.top;
});

window.addEventListener('keydown', function(event) {
  if (event.key === ' ') {
    event.preventDefault();
    splitPlayer();
  }
});

// Enhanced Start Button
document.getElementById('startButton').addEventListener('click', function() {
  const nameInput = document.getElementById('nameInput');
  const playerName = nameInput.value.trim();
  
  if (playerName && !gameRunning) {
    player.name = playerName;
    playerPieces[0].name = playerName;
    
    // Clear existing AI players
    allPlayers = [];
    generateAIPlayers();
    
    gameRunning = true;
    gameLoop();
    
    // Hide the name input after starting
    nameInput.style.display = 'none';
    this.textContent = '🎮 PLAYING...';
    this.disabled = true;
  } else if (!playerName) {
    alert('Please enter your name to start!');
    nameInput.focus();
  }
});

document.getElementById('stopButton').addEventListener('click', function() {
  if (gameRunning) {
    gameRunning = false;
    cancelAnimationFrame(gameLoopId);
    
    const startBtn = document.getElementById('startButton');
    const nameInput = document.getElementById('nameInput');
    
    startBtn.textContent = '🚀 START GAME';
    startBtn.disabled = false;
    nameInput.style.display = 'block';
  }
});

document.getElementById('restartButton').addEventListener('click', function() {
  window.location.reload();
});

// Initialize with some food
for (let i = 0; i < 1000; i++) {
  generateFood();
}

// Auto-focus name input
document.getElementById('nameInput').focus();