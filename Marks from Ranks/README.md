# 🚀 Marks from Ranks

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/find-marks-from-ranks/1) |

---

### 📝 Problem Statement

Consider an input where all marks obtained are divided into intervals of consecutive numbers represented as l[] and r[] where l[i] and r[i] represent the starting and ending marks (inclusive) of the i-th interval. 

The intervals are sorted in increasing order and do not overlap. 
The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.

Given an array rank[]. for each value in rank[], find the corresponding mark and return as an array.
Examples:


### Input:
 l[] = [1, 6, 14], r[] = [3, 9, 15], rank[] = [2, 5, 8]


### Output:
 [2, 7, 14]


### Explanation:
 The valid marks are 1, 2, 3, 6, 7, 8, 9, 14, 15. Their corresponding ranks are 1 to 9 as there are 9 distinct marks. Therefore, rank 2 corresponds to mark 2, rank 5 corresponds to mark 7, and rank 8 corresponds to mark 14.


### Input:
 l[] = [5, 10], r[] = [7, 12], rank[] = [1, 4, 6]


### Output:
 [5, 10, 12]


### Explanation:
 The valid marks are 5, 6, 7, 10, 11, 12. Their corresponding ranks are 1 to 6 in increasing order. Hence, rank 1 corresponds to mark 5, rank 4 corresponds to mark 10, and rank 6 corresponds to mark 12.

---

### 🏢 Topic Tags

> `Arrays` `Searching`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>