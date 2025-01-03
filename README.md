# cub3D
This project is a simplified recreation of the game Wolfenstein 3D, featuring a raycasting algorithm to render the maze.

📋 Project Overview

This project is a simplified recreation of the classic game Wolfenstein 3D, implemented in C. The game uses a raycasting algorithm to render a 3D maze from a 2D map. The player navigates the maze from a first-person perspective, experiencing a retro-style 3D environment. The display is handled using the MiniLibX (MiniLibX Graphics Library).

The focus of this project is to explore foundational game development techniques and computer graphics concepts, such as:

Raycasting

Grid-based movement

Handling player input

Rendering 2D maps into 3D spaces

🖥️ Technologies Used

Language: C

Graphics Library: MiniLibX (mlx)

Platform: linux

📐 How Raycasting Works

Raycasting is a rendering technique that simulates a 3D perspective by casting rays from the player's position into the game world to determine what walls and objects should be displayed on the screen.

Here's a brief breakdown of the process:

Raycasting Loop: The player’s field of view is divided into vertical strips, and rays are cast to detect walls in the maze.

Distance Calculation: The distance between the player and the walls is calculated to determine how tall the walls should appear.

Wall Rendering: Based on the distance, walls are drawn as vertical strips, creating the illusion of depth.


🚀 Getting Started

Prerequisites

linux

MiniLibX library (included in the project)

Building the Project

Clone the repository and run the following command to compile the project:

make

Running the Game

After building the project, launch the game with:

./cub3d maps/test1.cub

Example:

./cub3d maps/test1.cub

🎮 Controls

Key

Action

W : Move forward

S : Move backward

A : Move left

D : Move right

Left arrow: Turn left

Right arrow: Turn right

ESC : Quit the game

📋 Map Files

Map files are simple text files that define the layout of the maze. They use the following format:

0: Empty space

1: Wall

O, N, S or W: Player starting position and viewing direction

Example of a basic map:

111111
100001
100W01
100001
111111

🖼️ MiniLibX Library

The MiniLibX (mlx) is a lightweight graphics library used to handle window creation, drawing, and event handling in the game. It's compatible with linux and is commonly used in game development projects.


⚙️ Future Improvements

Some potential features to add in future updates:

Textured walls

A moving minimap

