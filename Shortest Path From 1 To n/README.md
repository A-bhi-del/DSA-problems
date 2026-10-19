# 🚀 Shortest Path From 1 To n

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟢 ![Easy](https://img.shields.io/badge/Easy-success?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1) |

---

### 📝 Problem Statement

Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j if and only if either j = i + 1 or j = 3 * i. The task is to find the minimum number of edges in a path from vertex 1 to vertex n.Examples:

### Input:
 n = 4


### Output:
 2


### Explanation:
 Possible paths from 1 to 4 are, 1 -> 2 -> 3 -> 4 and 1 -> 3 -> 4. Second path of length 2 is the shortest.

### Input:
 n = 9


### Output:
 2


### Explanation:
 Many paths are possible from 1 to 9. Shortest one possible is, 1 -> 3 -> 9, of length 2.

### Input:
 n = 15


### Output:
 4


### Explanation:
 Many paths are possible from 1 to 15. Shortest one possible is, 1 -> 3 -> 4 -> 5 -> 15, of length 4.

---

### 🏢 Topic Tags

> `Mathematics` `Graph` `Shortest Path`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>