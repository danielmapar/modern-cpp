# CPPND: Capstone Snake Game

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`. Use the `-d` flag to show debugging messages: `./SnakeGame -d`.

## Rubric Overview

### The README includes information about each rubric point addressed.
- [x] A README with instructions is included with the project
- [x] The README indicates which project is chosen.
- [x] The README includes information about each rubric point addressed.

### Compiling and Testing (All Rubric Points REQUIRED)
- [x] The submission must compile and run.

### Loops, Functions, I/O
- [x] The project demonstrates an understanding of C++ functions and control structures.
  * An example can be found on `line 25` of `game.cpp`.
- [x] The project reads data from a file and process the data, or the program writes data to a file.
  * An example can be found on `line 79` of `player_data.cpp` function `GetScoreBoard`.
- [x] The project accepts user input and processes the input.
  * An example can be found on `line 23` of `setup_screen.cpp` function `Run`.

### Object Oriented Programming

- [x] The project uses Object Oriented Programming techniques.
  * An example can be found on `line 15` of `screen.h`. This is the base class for `game_screen.cpp`, `setup_screen.cpp` and `score_screen.cpp`
- [x] Classes use appropriate access specifiers for class members.
  * An example can be found on `line 7` of `player_data.h`. 
- [x] Class constructors utilize member initialization lists.
  * An example can be found on `line 9` of `game_screen.cpp`. 
- [x] Classes abstract implementation details from their interfaces.
  * An example can be found on `line 12` of `player_data.h` function `Save`. This function is not useful for the users of this class.
- [x] Classes encapsulate behavior.
  * An example can be found on `line 26` of `game_screen.h`. Properties are `private` and can only be accessed by `public` functions.
- [x] Classes follow an appropriate inheritance hierarchy.
  * An example can be found on `line 15` of `screen.h`. This is the base class for `game_screen.cpp`, `setup_screen.cpp` and `score_screen.cpp`
- [x] Overloaded functions allow the same function to operate on different parameters.
  * An example can be found on `line 15` of `screen.h`. This is the base class for `game_screen.cpp`, `setup_screen.cpp` and `score_screen.cpp`
- [x] Derived class functions override virtual base class functions.
  * An example can be found on `line 15` of `game_screen.h`. 
- [ ] Templates generalize functions in the project.

### Memory Management

- [x] The project makes use of references in function declarations.
  * An example can be found on `line 15` of `game_screen.h`.
- [ ] The project uses destructors appropriately.
- [ ] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- [x] The project follows the Rule of 5. 
  * An example can be found on `line 15` of `game_screen.h`.
- [x] The project uses move semantics to move data, instead of copying it, where possible.
  * An example can be found on `line 24` of `game.cpp`. I did not implement or use move/copy in my custom classes
- [x] The project uses smart pointers instead of raw pointers.
  * An example can be found on `line 24` of `game.cpp`. 

### Concurrency

- [x] The project uses multithreading.
  * An example can be found on `line 65` of `game_screen.cpp` function `Run`.
- [ ] A promise and future is used in the project.
- [x] A mutex or lock is used in the project.
  * An example can be found on `line 114` of `game_screen.cpp` function `PlaceFood`.
- [ ] A condition variable is used in the project.

## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
