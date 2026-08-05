# Assignment 3 – Graph Traversal

## Overview
This project implements graph traversal algorithms using **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** in C++. The graph is represented using adjacency lists and supports both **directed** and **undirected** graphs. The program reads graph data from an input file and performs graph operations through an interactive command-driven interface. :contentReference[oaicite:0]{index=0}

## Features
- Read graph data from an input file
- Support for Directed and Undirected graphs
- Adjacency List representation
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Print complete adjacency lists
- Print adjacency list for a single vertex
- Display BFS traversal attributes
- Display DFS traversal attributes
- Interactive command-line execution

## Concepts Demonstrated

- Graph Data Structures
- Adjacency Lists
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Queue Data Structure
- Dynamic Memory Allocation
- File Input/Output
- Modular Programming
- Command-Line Arguments
- Linux Development Environment

## Project Structure
```text
Assignment03-Graph-Traversal/
│
├── main.cpp
├── graph.cpp
├── queue.cpp
├── util.cpp
├── data_structures.h
├── graph.h
├── queue.h
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
PJ3
```

## Running the Program
Example:

```bash
./PJ3 G01.txt DirectedGraph 1
```

or

```bash
./PJ3 G02.txt UndirectedGraph 0
```

The program accepts commands such as:

```text
ADJPrintAll
ADJPrintOne 3
BFS 1
BFSPrintAll
DFS
DFSPrintAll
Stop
```

## Learning Outcomes
Through this project, I gained practical experience with:
- Graph representation using adjacency lists
- Implementing Breadth-First Search (BFS)
- Implementing Depth-First Search (DFS)
- Queue implementation for graph traversal
- Graph traversal algorithms with O(V + E) time complexity
- Dynamic memory management in C++
- Modular software design
- Linux command-line development

## Technologies Used
- **Language:** C++
- **Compiler:** g++
- **Platform:** Linux (Ubuntu)
- **Build Tool:** Make

## Notes
This project was completed as part of a university Data Structures and Algorithms course and is shared for educational and portfolio purposes.

Only my implementation is included in this repository. Official assignment materials, starter code, and grading test cases are excluded where redistribution may conflict with course policies.
