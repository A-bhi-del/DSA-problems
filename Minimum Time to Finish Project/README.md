# 🚀 Minimum Time to Finish Project

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/project-manager--141631/1) |

---

### 📝 Problem Statement

An IT company is working on a large project consisting of n modules. The given array time required (in months) to complete the ith module is stored in the array duration[]. The array dependencies[][], where dependencies[i] = [u, v], indicates that module v can be started only after module u is completed. Multiple modules can be worked on simultaneously as long as all their dependencies have been completed. Find the minimum time required to complete the entire project. If the project cannot be completed due to a cyclic dependency, return -1. A module is never dependent on itself.Examples

### Input:
 duration[] = [10, 20, 30, 10, 30, 20], dependencies[][] = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]


### Output:
 80


### Explanation:
 
The Graph of dependency forms this and the project will be completed when Module 1 is completed. The minimum taken time is 80 months, the maximum taken time is through the path 5 -> 2 -> 3 -> 1 which takes 20 + 30 + 10 + 20

### Input:
 duration[] = [5, 5, 5], dependencies[][] = [[0, 1], [1, 2], [2, 0]]


### Output:
 -1


### Explanation:
 There is a cycle in the dependency graph hence the project cannot be completed.

---

### 🏢 Topic Tags

> `DFS` `Sorting` `Graph`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>