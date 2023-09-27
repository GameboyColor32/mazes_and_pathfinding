# Random Maze Generator in C

This is a simple command-line program written in C that generates random mazes in ASCII art format. You can specify the width and height of the maze as command-line arguments. The program uses a generic queue implemented with void pointers.

## Compilation

To compile the program, make sure you have `gcc` (GNU Compiler Collection) and `make` installed on your system. Then, run the following command in the project directory:

```bash
make
```

This will compile the source code and generate an executable file named dante.

## Usage

To generate a random maze, use the following command-line syntax:
```bash
./dante <width> <height>
```
Replace <width> and <height> with the desired dimensions of the maze. For example, to create a 10x10 maze, you can run:
```bash
./dante 10 10
```
The program will generate a random maze of the specified size and print it to the command line.
## Generic Queue Implementation

The program includes a generic queue implementation using void pointers. This queue data structure is used internally to facilitate maze generation. The queue is designed to work with any data type, making it flexible and reusable. While this is not the best thing to do in C, it was a nice exercice to try out.