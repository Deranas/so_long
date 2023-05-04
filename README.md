# so_long
small game that'll create a level based on the passed map.ber where a knight has to collect all treasure before exciting through a door! :)

## Getting Started
```
🚨 Please check that you have MLX42-Library installed on your machine.
```
### Install
```bash
$ make
```
if you get an error from the MLX42-library about it's filepath, try 
```bash
$ make fclean
$ make
```

### Usage
```bash
$ ./so_long [MAP_FILE.ber]
```
Only map files with extension `.ber` are supported. One map.ber to use is included in the root respository.

```bash
$ ./so_long map.ber
```
Run this command to use all the features of the game.

### HOW TO PLAY
The player’s goal is to collect all treasures present on the map then escape with minimal movement through the door.

|KEYBOARD|ACTION|
|---|---|
|`↑`|Move up|
|`↓`|Move down|
|`←`|Move left|
|`→`|Move right|
|`ESC ⎋`|Close the game window|

## Reference
 * [MLX42 graphic library](https://github.com/codam-coding-college/MLX42)
