# cub3D

Cub3D is a project that explores the fundamentals of raycasting, offering a hands-on experience in creating a simple 3D game using the C programming language and the MiniLibX graphics library. 

Small presentation: (need to add video small video for demo)

## Step 1 (The project can run on both Ubuntu 23.10 and macOS):

### Ubuntu 23.10 REQUIREMENTS
If you're running on a Linux machine, the project will rely on 42 Paris' [miniLibX](https://github.com/42Paris/minilibx-linux).
You can find the requirements by clicking on the link or just reading what's required below (which is basically a copy/paste from the README): 
```txt
1. MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
2. gcc
3. make
4. X11 include files (package xorg)
5. XShm extension must be present (package libxext-dev)
6. Utility functions from BSD systems - development files (package libbsd-dev)
```
Run this command on you Linux machine in order to fullfill the requirements above.
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)
```
### MacOS REQUIREMENTS
As for Mac Users, we will rely on another minilibX. The only requirements you will need is [XQuartz](https://www.xquartz.org/) installed.

## MAKE & PLAY (even if it's not really a game...)
Create the binary using the make command on your terminal.
```bash
make
```
__./cub3D__ binary will be created. Now the only thing left to do is to provide a map as a second argument.
__ONLY__ <filename>.cub are accepted by this program. So make sure to launch executable like so with the right map path:

```bash
./cub3D ./maps/valid/basic.cub
```
You can already find map examples inside the maps folder, both including valid and invalid maps.
Check out the format of the map below:
```txt
NO ./textures/minecraft/north.xpm // NORTH texture
SO ./textures/minecraft/south.xpm // SOUTH texture
WE ./textures/minecraft/west.xpm // WEST texture
EA ./textures/minecraft/east.xpm // EAST texture

F 230,30,0 // floor colour
C 0,30,255 // ceiling colour

// the MAP enclosed by walls => (1) :

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111 // With ONE PLAYER => 'N' 
11110111 1110101 101111010001
11111111 1111111 111111111111
```
The player can be positioned north ('N'), south ('S'), east ('E'), or west ('W').

## Game LAUNCHED.
### W, A, S, D keys + ROTATION keys
```txt
# --- movements keys --- #
W => MOVE UP
A => MOVE LEFT
S => MOVE DOWN
D => MOVE RIGHT

# --- arrow keys --- #
LEFT ARROW => ROTATE TO THE LEFT
RIGHT ARROW => ROTATE TO THE RIGHT
```
Explore around the map if you'd like.

# BONUS PART
A few bonuses were added:
1. The addition of a minimap.
2. Wall collision. (already included in the mandatory part)
3. Mouse movements. (ONLY horizontal)
4. Doors (open & close).

Run:
```bash
make bonus
```
A __cub3D_bonus__ binary will be generated. If you'd like to see a door, include a map with the character '2' in it.
And if you'd like to open/close the door when the game is running, press the SPACEBAR key when you're located nearby it.
