# libmy

This is a git repository for the "libmy" library that I used during my first year at Epitech. The library provides a range of helpful functions, such as memory allocation, string manipulation, and standard I/O operations. It also includes an implementation of doubly linked lists.

## Project Structure

This repository contains a C library with several modules:

- `lib/include`: header files for the library.
- `lib/src`: source code for the library, divided into four modules:
    - `m_list`: implementation of doubly linked lists.
    - `m_stdio`: implementation of standard input/output functions.
    - `m_stdlib`: implementation of memory allocation and conversion functions.
    - `m_string`: implementation of string manipulation functions.

## Usage

To use the library in your C project, include the relevant header files in your source files and link the library files during the compilation process. The library files can be compiled by running the command `make` in the root directory of the project. The library file will be generated in the `lib` folder.

The `tests` folder contains several unit tests for the library. Tests for the `m_list`, `m_stdio`, `m_stdlib`, and `m_string` modules are in separate files with names starting with `test_`. To run the tests and get a coverage report, run `make tests_run`.

To clean up the compiled object files, run the command `make clean`. To remove both the object files and the library file, run the command `make fclean`. And to recompile everything, run the command `make re`.

## Dependencies

This library has no external dependencies, and should compile without any issues on most Unix-based systems.

## Contributing

If you would like to contribute to this library, please fork the repository and submit a pull request with your changes. Please make sure that your code follows the Epitech coding style and that any new functionality is thoroughly tested.

## Author

This library was created by T1ld3, an Epitech student.
