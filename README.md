# Game-Of-Life
A very bare-bones demonstration of John Conway's Game of Life.

<img src="https://github.com/henrydenny246/Game-Of-Life/blob/master/GameOfLife.png" alt="Game-Of-Life" width="400"> 

# Usage
```Game-Of-Life.exe [image]```

* In the case that a pathname to an image is omitted, the program will create a blank Game of Life world.

* If instead, a pathname to an image is included, the image will be read into the program and a new Game of Life world will be created from the image. The coordinate of each pixel in the image corresponds to the coordinate of the cell in the world. A black pixel counts towards a dead cell and any other colour counts towards an alive one. Refer to ```gosperglidergun.png``` and ```test.png``` in the bin folder for examples.

# Controls
| Command |    Action   |
|:-------:|:-----------:|
|   LMB   | Create cell |
|  Space  |    Pause    |

# Running (Windows only)
To run:
1. Download the contents of the bin folder.
2. Refer to [Usage](#usage)
