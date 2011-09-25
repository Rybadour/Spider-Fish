Spider Fish
===========

Building with cmake
=======

First, download and install cmake.
    http://www.cmake.org/

Run the following commands:

    $ cd build
    $ cmake ../

This will generate a build system appropriate for your environment in the
`build` directory. Built binaries will be located in `build/bin`.

Running the game
=======

1. Build the game.
2. If on Windows, copy all dlls from `lib` to the same directory as the
   `spifi_game` executable. 
3. Copy images into the same directory as the executable, or if using 
	Visual Studios copy the images into the project directory.
4. Run the `spifi_game` executable in `build/bin`.

Directory structure
=======

* /build - build system and built binaries
* /include - third-party header files
* /lib - prebuilt third-party libraries
* /src - cpp source files
* /resources - images, audio files, etc
