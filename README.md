# 🧩 Rubik's Cube Solver

An optimized **3×3 Rubik's Cube Solver** built from scratch in **C++**, focusing on graph search algorithms, heuristic search, and efficient state representation.

This project was developed to understand how classical AI search algorithms can be applied to solve one of the most challenging combinatorial puzzles.

---

## 🚀 Features

* Complete 3×3 cube representation
* Implementation of all basic cube moves

  * R, R'
  * L, L'
  * U, U'
  * D, D'
  * F, F'
  * B, B'
* Cube state encoding for fast hashing
* Algorithm parser to execute move sequences
* Breadth First Search (BFS)
* Iterative Deepening DFS (IDDFS)
* Iterative Deepening A* (IDA*)
* Custom heuristic function
* Performance comparison between search algorithms

---

## 📊 Algorithms Implemented

### Breadth First Search (BFS)

Implemented as the baseline solver using state hashing.

**Limitation**

* Memory consumption grows exponentially.
* Practical only for very small scramble depths.

---

### Iterative Deepening DFS (IDDFS)

Implemented to reduce memory usage while guaranteeing optimal solutions.

**Advantages**

* Uses very little memory.
* Finds shortest solutions.

---

### Iterative Deepening A* (IDA*)

Implemented heuristic-guided search to significantly reduce the number of explored states.

The solver prunes states using:

```text
f(n) = g(n) + h(n)
```

where:

* **g(n)** = moves performed so far
* **h(n)** = heuristic estimate of remaining distance

---

## 📈 Performance

Example comparison:

| Algorithm | Nodes Explored |  Time |
| --------- | -------------: | ----: |
| IDDFS     |           20M+ | ~55 s |
| IDA*      |          ~1.1M | ~39 s |

*(Performance depends on scramble length and heuristic quality.)*

---

## 🛠 Technologies Used

* C++
* STL
* Graph Search Algorithms
* Heuristic Search
* State Encoding
* Git & GitHub

---

## 🔄 Current Progress

* [x] Cube Representation
* [x] Move Engine
* [x] BFS Solver
* [x] IDDFS Solver
* [x] IDA* Solver
* [ ] Improved Heuristics
* [ ] Node.js Backend API
* [ ] Interactive Web Interface
* [ ] Online Deployment

---

## 🎯 Future Improvements

* Corner and edge-based heuristics
* Pattern Database heuristic
* Node.js + Express backend
* Interactive web visualizer
* Real-time cube animation
* Deployment as a full-stack web application

---

## 📚 Learning Outcomes

Through this project I gained hands-on experience with:

* Graph search algorithms
* Heuristic search
* Backtracking
* State space optimization
* Hashing and state encoding
* Algorithm performance analysis
* Software design for complex systems
