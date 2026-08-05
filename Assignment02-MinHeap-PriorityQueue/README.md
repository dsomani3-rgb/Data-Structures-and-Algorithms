# Assignment 2 – Min Heap Priority Queue

## Overview
This project implements a **Min Heap** data structure using an array-based representation in C++. The heap functions as a priority queue and supports common heap operations while maintaining the min-heap property.

The implementation was developed as part of a Data Structures and Algorithms coursework to strengthen understanding of heap construction, priority queues, and efficient data organization.

## Features
- Read input data from a file
- Initialize an empty heap
- Build a Min Heap
- Insert elements into the heap
- Extract the minimum element
- Decrease the key of an existing element
- Print heap contents
- Print the underlying array
- Write heap data to an output file
- Interactive command-driven execution

## Concepts Demonstrated
- Min Heap
- Priority Queue
- Heapify
- Build Heap
- Dynamic Memory Allocation
- Arrays
- File Input and Output
- Command-Line Arguments
- Modular Programming
- Linux Development Environment

## Project Structure
```text
Assignment02-MinHeap-PriorityQueue/
│
├── main.cpp
├── heap.cpp
├── util.cpp
├── data_structures.h
├── heap.h
├── util.h
├── main.h
├── Makefile
└── README.md
```

## Building the Project
Compile the project using:

```bash
make
```

This generates the executable:

```text
PJ2
```

## Running the Program
Example:

```bash
./PJ2 input.txt output.txt
```

The program accepts commands interactively, including:

```text
Read
BuildHeap
PrintHeap
Insert 5
ExtractMin
DecreaseKey 3 2.5
Write
Stop
```

## Learning Outcomes
Through this project, I gained practical experience with:
- Implementing an array-based Min Heap
- Understanding Priority Queue operations
- Maintaining heap properties efficiently
- Working with dynamic memory management
- Building modular C++ applications
- Using Linux command-line tools and Makefiles
- Processing input and output files

## Technologies Used
- **Language:** C++
- **Compiler:** g++
- **Platform:** Linux (Ubuntu)
- **Build Tool:** Make

## Notes
This project was completed as part of a university Data Structures and Algorithms course and is shared for educational and portfolio purposes.

Only my implementation is included in this repository. Official assignment materials, starter code, and grading test cases are excluded where redistribution may conflict with course policies.
