# Game Sound Assets

This directory contains sound effects for the Brick Breaker game.

## Required Sound Files

- `hit.mp3` - Sound when ball hits paddle or walls
- `break.mp3` - Sound when brick is destroyed
- `powerup.mp3` - Sound when power-up is collected
- `gameover.mp3` - Sound when game ends

## Sound Specifications

- Format: MP3
- Sample Rate: 44.1 kHz
- Bit Rate: 128 kbps or higher
- Duration: Keep under 2 seconds for best performance

## Adding Custom Sounds

1. Place your sound files in this directory
2. Update the audio elements in `frontend/index.html`
3. Update the sound references in `frontend/game.js`

## Free Sound Resources

- Freesound.org
- OpenGameArt.org
- Zapsplat.com (free tier)

## Note

For the mobile app, sounds are handled differently through React Native Sound library.