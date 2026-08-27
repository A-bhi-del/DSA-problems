# 🚀 Minimum Cost Selection

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/buying-vegetables0016/1) |

---

### 📝 Problem Statement

Given an n × 3 matrix mat[][], where each row represents the costs of three available choices at a shop, select exactly one choice from each row such that the same choice is not selected in two adjacent rows. 
Return the minimum total cost required.
Examples:


### Input:
 mat[][] = [[1, 50, 50], [50, 50, 50], [1, 50, 50]]


### Output:
 52


### Explanation:
 One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 50), Row 3: Choice 1 (Cost = 1)
Total cost = 1 + 50 + 1 = 52.


### Input:
 mat[][] = [[1, 4, 1], [3, 2, 2], [3, 2, 3]]


### Output:
 5


### Explanation:
 One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 2), Row 3: Choice 3 (Cost = 2)
Total cost = 1 + 2 + 2 = 5.

---

### 🏢 Topic Tags

> `Dynamic Programming`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>