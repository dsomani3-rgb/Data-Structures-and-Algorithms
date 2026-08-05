# Data-Structures-and-Algorithms
My C++ implementations and coursework for Data Structures and Algorithms.
# Assignment 1 – Linked List Manager (C++)

## Overview
This project is a C++ implementation of a **singly linked list** developed as part of a Data Structures and Algorithms coursework. It demonstrates the use of dynamic memory management, modular programming, file I/O, and command-line arguments in a Linux environment.
The application provides an interactive command-driven interface that allows users to perform common linked list operations while reading from and writing to files.

## Features
* Insert a node at the beginning of the list
* Append a node to the end of the list
* Delete a node by key
* Search for a node
* Print the linked list
* Find the maximum value
* Find the minimum value
* Calculate the sum of all elements
* Display the current list length
* Read data from an input file
* Write data to an output file
* Release dynamically allocated memory

## Concepts Demonstrated
* Singly Linked Lists
* Dynamic Memory Allocation (`malloc` / `free`)
* File Input and Output
* Command-Line Arguments
* Modular Programming
* Header and Source File Organization
* Makefiles
* Linux Development Environment

## Project Structure
```text
Assignment01-LinkedList/
│
├── main.cpp
├── util.cpp
├── list_read.cpp
├── list_write.cpp
├── structs.h
├── util.h
├── list_read.h
├── list_write.h
├── Makefile
└── README.md
```

## Building the Project
Compile the project using the provided Makefile:

```bash
make
```

This generates the executable:

```text
PJ1
```

## Running the Program
Example:

```bash
./PJ1 input.txt output.txt 2
```

where:

* `input.txt` contains the input data
* `output.txt` is the generated output file
* `2` is the program flag controlling output behavior

The program accepts commands interactively (or through redirected input), such as:
```text
Read
Append 10
Insert 5
Print
Max
Search 10
Delete 5
Stop
```

## Learning Outcomes
Through this project, I gained practical experience with:
* Implementing and manipulating linked lists
* Managing dynamic memory safely
* Designing modular C++ programs
* Working with command-line applications on Linux
* Reading from and writing to files
* Building projects using Makefiles

## Technologies Used
* **Language:** C++
* **Compiler:** g++
* **Platform:** Linux (Ubuntu)
* **Build Tool:** Make

## Notes
This repository showcases my implementation completed as part of a university Data Structures and Algorithms course. It is intended for educational and portfolio purposes.

Official assignment materials, starter code, and grading test cases are not included where redistribution may conflict with course policies.
