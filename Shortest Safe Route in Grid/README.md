# 🚀 Shortest Safe Route in Grid

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1) |

---

### 📝 Problem Statement

Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.You can move only in four directions: up, down, left, and right. A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided. Return -1 if no safe path exists.Examples:

### Input:
 mat[][] = [[1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]]

### Output:
 6


### Explanation:
 We can see that length of shortest safe route is 6. 

### Input:
 mat[][] = [[1, 1, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 1, 1]]

### Output:
 -1


### Explanation:
 There is no possible path from first column to last column.

---

### 🏢 Topic Tags

> `DFS` `Graph`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>