# Trading Overlay

A graph visualization program built with C++ and the raylib library.

![Nagranie ekranu_20260212_213808](https://github.com/user-attachments/assets/b86df550-9d58-40e6-a8b2-69150b6d5efb)

## Requirements

- g++ compiler (C++17 standard)
- make build tool
- raylib library (installed on system)
- System libraries: GL, m, pthread, dl, rt, X11

## Project Structure

- `src/`: source files (.cpp, .h)
- `build/`: build directory containing the Makefile and binary output

### NEEDED

- `data.txt`: Place a text file with the data you want to visualize in the src folder.

## Compilation

To compile the project, navigate to the build directory and use make:

```bash
cd build
make

