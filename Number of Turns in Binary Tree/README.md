# 🚀 Number of Turns in Binary Tree

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🔴 ![Hard](https://img.shields.io/badge/Hard-critical?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1) |

---

### 📝 Problem Statement

Given root of a binary tree and the values of its two nodes p and q, count turns required to travel from node p to q. 

A turn occurs whenever the direction of movement changes from left to right or right to left while traversing the tree. 
If the path between the two nodes does not involve any turns (i.e., the nodes lie on the same straight path), return -1. 

Note: All node values are distinct.
Examples :


### Input:
 root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 5, q = 10

### Output:
 4


### Explanation:
 The path from node 5 to node 10 is: 5 -> 2 -> 1 -> 3 -> 6 → 10. Direction changes occur at nodes 2, 1, 3, and 6. Therefore, the number of turns is 4.



### Input:
 root[] = [1, 2, 3, 4, 5, 6, 7, 8, N, N, N, 9, 10], p = 1, q = 4

### Output:
 -1


### Explanation:
 No turn is required since they are in a straight line.


### Constraints:
1 ≤ n ≤ 104, n is the number of nodes1 ≤ node->data ≤ 1041 ≤ p, q ≤ n

---

### 🏢 Topic Tags

> `Tree`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>