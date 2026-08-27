# 🚀 Negative Weight Cycle

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1) |

---

### 📝 Problem Statement

Given a weighted directed graph containing V vertices numbered from 0 to V - 1 and a list of E directed edges edges[][], determine whether the graph contains a negative weight cycle or not. 
Each edge is represented as: [u, v, w], where there is a directed edge from vertex u to vertex v having the given weight w.
Note: A negative-weight cycle is a cycle in a graph whose edges sum to a negative value.
Examples:


### Input:
 V = 4, E = 4, edges[][] = [[0, 3, 6], [1, 0, 4], [1, 2, 6], [3, 1, 2]]


### Output:
 false


### Explanation:
 Cycle 1 -> 0 -> 3 -> 1 has total weight 6 + 4 + 2 = 12, which is positive, so no negative weight cycle exists.


### Input:
 V = 4, E = 4, edges[][] = [[1, 0, 4], [3, 1, -2], [1, 2, -6], [2, 3, 5]]


### Output:
 true


### Explanation:
 There is a cycle 1 -> 2 -> 3 -> 1 with total weight -3, which is negative, so a negative weight cycle exists.
 

### Constraints:
1 ≤ V ≤ 1030 ≤ E ≤ 1050 ≤ u, v < V-106 ≤ w ≤ 106

---

### 🏢 Topic Tags

> `Graph`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>