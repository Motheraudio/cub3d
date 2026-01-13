# cub3D
![alt text](https://github.com/Motheraudio/cub3d/blob/main/screenshots/example1.png)

A raycasting game engine written in C that renders a 3D maze from a first-person perspective, inspired by classic games like Wolfenstein 3D.   

## What is this?

This project takes a 2D map described in a `.cub` file and renders it as a 3D environment you can walk through. It uses raycasting to simulate 3D graphics without actual 3D rendering, giving you that retro FPS look while being computationally efficient.  

## Requirements

- GCC or compatible C compiler
- Make
- [@42paris/minilibx-linux](https://github.com/42paris/minilibx-linux) - Graphics library for Linux
- X11 development libraries (`libX11`, `libXext`)
- Math library (`libm`)

## How it works

The engine is built on three main systems that work together: 

### Parsing

The parser reads `.cub` configuration files that define:
- Wall textures for each cardinal direction (NO, SO, WE, EA)
- Floor and ceiling colors in RGB format
- A 2D map layout using characters: 
  - `1` for walls
  - `0` for walkable floor
  - `N`, `S`, `E`, `W` for player start position and orientation
  - Spaces for empty areas

Example map format:
```
NO ./textures/north_wall. xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall. xpm
EA ./textures/east_wall.xpm

F 0,255,0
C 255,254,253

111111
100001
1000N1
111111
```

The parsing system validates the map structure, checking that walls properly enclose the playable area and that there's exactly one player spawn point.

### Raycasting

This is where the magic happens.  The raycasting system shoots out rays from the player's position at regular angular intervals across their field of view (30 degrees). Each ray travels until it hits a wall. 

For each ray, the system: 
- Calculates the distance to the wall
- Records which wall was hit and where
- Stores color information from a minimap-based color coding system

The raycasting uses Bresenham's line algorithm to efficiently trace rays pixel by pixel through the 2D map.  It casts 960 rays per frame, which get stretched to fill the 1920-pixel-wide screen. 

### 3D Projection and Rendering

Once we have all the raycast data, the projection system converts those distances into vertical wall slices on screen.  The core formula is: 

```
wall_height = (TILESIZE * SCREEN_HEIGHT) / distance
```

To prevent the fisheye effect (where walls look curved), distances get corrected based on the angle between each ray and the player's view direction: 

```
corrected_distance = distance * cos(angle_difference)
```

Each wall slice: 
1. Gets its height calculated from the corrected distance
2. Is centered vertically on screen
3. Has the appropriate texture column applied
4. Gets texture coordinates that scale properly regardless of wall height

The renderer also handles floor and ceiling by simply filling the top and bottom halves of the screen with the configured colors.

## Project Structure

```
cub3d/
├── parsing/          # Map and config file parsing
├── raycasting/       # Ray projection and wall detection
├── projection/       # 3D view rendering and texture mapping
├── render/           # Graphics initialization, minimap, and drawing utils
├── game_loop/        # Main loop, input handling, player movement
├── cleanup/          # Memory management
├── libft/            # Utility functions
└── files/            # Example . cub map files
```

## Building and Running

Compile with:  
```bash
make
```

Run with a map file:
```bash
./cub3D files/test1.cub
```

Controls:
- `W/A/S/D` - Move around
- Arrow keys - Rotate view
- `ESC` - Exit

## Technical Details
![alt text](https://github.com/Motheraudio/cub3d/blob/main/screenshots/example2.png)
- Resolution: 1920x1080
- Field of view: 30 degrees (0.523598 radians)
- Ray count: 960 per frame
- Tile size: 64 pixels
- Graphics library: MiniLibX (mlx)

The engine runs at a controlled frame rate and uses MiniLibX for window management and pixel manipulation.  Each frame, the minimap is redrawn, raycasting is performed, and the 3D view is projected and displayed. 

## Credits

**[Motheraudio](https://github.com/Motheraudio)** - 3D rendering, projection, and testing  
**[chomamichal](https://github.com/ChomaMichal)** - Raycasting system, parsing, and minimap-based color coding system to check which wall and which section of the wall to project
