# 🚀 Sequences where Adjacent Divide

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/count-in-array2138/1) |

---

### 📝 Problem Statement

Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:

Each element is in the range [1, m].
All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.

Examples:


### Input:
 n = 3, m = 3
Output : 17


### Explanation:
 The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1], [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].



### Input:
 n = 1, m = 10 


### Output:
 10


### Explanation:
 The possible arrays are [1], [2], [3], [4], [5], [6], [7], [8], [9] and [10].

---

### 🏢 Topic Tags

> `Dynamic Programming` `Modular Arithmetic`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>