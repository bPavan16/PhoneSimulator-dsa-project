# README.md

# Phone Simulator

## Overview
The Phone Simulator is a C application that simulates basic phone functionalities using various data structures such as hashtables, heaps, graphs, linked lists, stacks, queues, and trees. This project serves as an educational tool to understand data structures and their applications in a real-world scenario.

## Project Structure
```
phone-simulator
├── src
│   ├── main.c
│   ├── data_structures
│   │   ├── hashtable.c
│   │   ├── hashtable.h 
│   │   ├── heap.c
│   │   ├── heap.h
│   │   ├── graph.c
│   │   ├── graph.h
│   │   ├── linkedlist.c
│   │   ├── linkedlist.h
│   │   ├── queue.c
│   │   ├── queue.h
│   │   ├── stack.c
│   │   ├── stack.h
│   │   ├── tree.c
│   │   └── tree.h
│   ├── simulator
│   │   ├── phone.c
│   │   └── phone.h
│   └── utils
│       ├── common.c
│       └── common.h
├── Makefile
└── README.md
```

## Setup Instructions
1. Clone the repository:
   ```
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```
   cd phone-simulator
   ```
3. Build the project using the Makefile:
   ```
   make
   ```

## Usage
After building the project, run the executable to start the phone simulator:
```
./phone-simulator
```

## Features
- Make calls
- Send messages
- Manage contacts using various data structures

## Contributing
Feel free to submit issues or pull requests for improvements and enhancements.