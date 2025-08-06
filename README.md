# Poison Candy

A two-player luck-based game built with C++ and Raylib where players must avoid poisoned candies to survive.

<img width="1199" height="694" alt="image" src="https://github.com/user-attachments/assets/ba73951a-ad5d-48aa-8eb6-6440f3da6814" />

## Overview

Poison Candy is a turn-based game for two players. The game features a grid of 30 candies where each player secretly selects one candy to poison. Players then take turns eating candies, trying to avoid the poisoned ones. The player who eats a poisoned candy loses the game.
This original game was inspired by a TikTok trend which followed the same rules and players ate actual candy.

## Game Rules

1. 30 candies are arranged in a 5×6 grid with random colors
2. Player 1 selects a candy to poison (Player 2 looks away)
3. Player 2 selects a different candy to poison (Player 1 looks away)
4. Players alternate turns eating candies
5. Eaten candies are removed from the board
6. If a player eats a poisoned candy, they lose immediately
7. The other player wins the game

## Features

- Mouse-controlled interface with visual feedback
- Multi-screen game flow (instructions, poison selection, gameplay, game over)
- Random candy colors for visual variety
- A candy is highlighted when mouse hovers over it
- Clean object-oriented C++ implementation
- Cross-platform compatibility through Raylib

## Installation & Setup

### Prerequisites
1. Install a C++ compiler (e.g., GCC or MinGW for Windows).
2. Install [Raylib](https://www.raylib.com/) (a simple and easy-to-use library for game development).
3. Ensure you have a terminal or command prompt to run commands.

### Building the Game
1. Clone or download the project
2. Navigate to project directory
3. Run the following command to compile the game:
```bash
make all
```
4. Or use this command to compile and run the game in one step:
```bash
make run
```

### Cleaning Build Files
To remove compiled files and clean the project, run:
```bash
make clean
```

## System Requirements

- C++ compiler with C++17 support
- Raylib graphics library
- Minimum display resolution: 1200×700 pixels
- Mouse input device

## Controls

- **Left Click**: Select candies and navigate menus
- **Mouse Hover**: Highlight candies for selection

## Project Structure

```
PoisonCandy/
├── headers/             # Header files
│   ├── Candy.hpp        # Candy class definition
│   ├── Screens.hpp      # Game screen states
│   └── Utils.hpp        # Utility functions
├── source/              # Implementation files
│   ├── Candy.cpp        # Candy class methods
│   └── Utils.cpp        # Utility implementations
├── main/                # Main application
│   └── Main.cpp         # Game logic and entry point
├── bin/                 # Compiled executables (generated)
├── obj/                 # Object files (generated)
├── Makefile             # Build configuration
└── .gitignore           # Version control ignore file
```

## Technical Implementation

The game is implemented using:
- **Language**: C++17
- **Graphics Library**: Raylib
- **Architecture**: Object-oriented design with separate classes for game components
- **Build System**: Makefile for cross-platform compilation
- **State Management**: Enum-based screen management

## Future Improvements

- Different grid sizes (4×4, 6×6, etc.)
- Improved graphics and animations
- Better visual indicators for game state
- Colorblind accessibility options
- Keyboard controls as alternative to mouse

## Building Notes

The project uses a Makefile that:
- Compiles all `.cpp` files from `source/` and `main/` directories
- Links against Raylib and required system libraries
- Generates executable in the `bin/` directory
- Supports Windows-specific flags (`-mwindows` for GUI application)
