# 🚀 Min Edge Movements to Connect a Graph

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/connecting-the-graph/1) |

---

### 📝 Problem Statement

Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. 
Find the minimum number of operations that will be required to connect the graph. If it is not possible to connect the graph, return -1.
Examples: 


### Input:
 n = 4, edges[][] = [[0, 1], [0, 2], [1, 2]]

### Output:
 1

### Explanation:
 Remove edge between vertices 1 and 2 and add between vertices 1 and 3.


### Input:
 n = 6, edges[][] = [[0,1], [0,2], [0,3], [1,2], [1,3]]

### Output:
 2

### Explanation:
 Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)

---

### 🏢 Topic Tags

> `Graph` `Disjoint Set`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>