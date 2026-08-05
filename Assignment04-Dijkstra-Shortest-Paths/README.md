# Assignment 4 – Dijkstra's Shortest Paths

## Overview
This project implements Dijkstra's Shortest Path Algorithm to compute both **single-pair** and **single-source** shortest paths in weighted graphs. The graph is represented using adjacency lists, while a **Min Heap** is used as the priority queue and a **Stack** is used to reconstruct and print the shortest path.
The implementation supports both **directed** and **undirected** graphs and provides an interactive command-driven interface for graph operations and shortest path queries. :contentReference[oaicite:0]{index=0}

## Features
- Read weighted graph data from an input file
- Support for Directed and Undirected graphs
- Adjacency List graph representation
- Dijkstra's Single-Pair Shortest Path
- Dijkstra's Single-Source Shortest Path
- Print adjacency lists
- Print shortest path length
- Print shortest path
- Min Heap priority queue implementation
- Stack-based path reconstruction
- Interactive command-line execution

## Concepts Demonstrated
- Graph Algorithms
- Dijkstra's Algorithm
- Shortest Path Computation
- Adjacency Lists
- Priority Queue (Min Heap)
- Stack Data Structure
- Dynamic Memory Allocation
- File Input/Output
- Modular Programming
- Linux Development Environment

## Project Structure
```text
Assignment04-Dijkstra-Shortest-Paths/
│
├── main.cpp
├── graph.cpp
├── heap.cpp
├── stack.cpp
├── util.cpp
├── data_structures.h
├── graph.h
├── heap.h
├── stack.h
├── util.h
├── main.h
├── Makefile
└── README.md
```

## Building the Project
Compile using:

```bash
make
```

This generates:

```text
PJ4
```

## Running the Program
Example:

```bash
./PJ4 network01.txt DirectedGraph 1
```

or

```bash
./PJ4 network02.txt UndirectedGraph 0
```

Example commands:

```text
PrintADJ
SinglePair 1 5
PrintLength 1 5
PrintPath 1 5
SingleSource 1
PrintPath 1 8
Stop
```

## Learning Outcomes
Through this project, I gained practical experience with:

- Implementing Dijkstra's shortest path algorithm
- Designing efficient graph representations
- Using Min Heaps as priority queues
- Reconstructing shortest paths using stacks
- Optimizing graph algorithms with adjacency lists
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
