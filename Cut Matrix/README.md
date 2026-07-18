# 🚀 Cut Matrix

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🔴 ![Hard](https://img.shields.io/badge/Hard-critical?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/cut-matrix/1) |

---

### 📝 Problem Statement

Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at least one 1 in it. A cut can be made in the following way:

Choose a direction: vertical or horizontal.
Choose an index to cut the matrix into two pieces.
If the cut is horizontal, only the bottom part can be cut further.
If the cut is vertical, only the right part can be cut further.

Return the number of different ways to divide the matrix modulo 1e9 + 7.
Examples:


### Input:
 matrix = [[1, 0, 0], [1, 1, 1], [0, 0,0]], k = 3 

### Output:
 3

### Explanation:
 There are 3 valid ways to divide the matrix into 3 pieces each having at least one 1 - horizontal cut after row 0 then vertical cut after col 0 on bottom, horizontal cut after row 0 then vertical cut after col 1 on bottom, and vertical cut after col 0 then vertical cut after col 1 on the right part. 


### Input:
 matrix = [[0, 0], [1, 1]], k = 2

### Output:
 1

### Explanation:
 Only way is to cut vertically in the middle since the top half has no 1.


### Input:
 matrix = [[1, 0], [0, 0]], k = 1

### Output:
 1

### Explanation:
 No cut needed as k = 1, the whole matrix is one piece with at least one 1.


### Constraints:
1 <= n, m, k <= 200

---

### 🏢 Topic Tags

> `Dynamic Programming`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>