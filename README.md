# Trading Overlay

A graph visualization program built with C++ and the raylib library.

## Requirements

- g++ compiler (C++17 standard)
- make build tool
- raylib library (installed on system)
- System libraries: GL, m, pthread, dl, rt, X11

## Project Structure

- src/: source files (.cpp, .h) and data.txt
- build/: build directory containing the Makefile and binary output

## Compilation

To compile the project, navigate to the build directory and use make:

cd build
make

The build process automatically copies src/data.txt to the build directory so the executable can access the data at runtime.

## Running

Run the program from the build directory:

./text

Alternatively, you can use:

make run

## Features

- Graph connection rendering based on input data
- View navigation using the Left Arrow key (KEY_LEFT)
- Console logging for mouse positions and movement delta during drag-and-drop operations

## Cleaning

To remove object files and the executable:

make clean

