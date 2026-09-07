# 🚀 Minimum Elements Outside Subsequences

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🔴 ![Hard](https://img.shields.io/badge/Hard-critical?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence2617/1) |

---

### 📝 Problem Statement

Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence. 
Each element can belong to at most one of these subsequences, and some elements may remain unused. 
Determine the minimum number of elements that cannot be included in either subsequence.
Examples:


### Input:
 arr[] = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]


### Output:
 2


### Explanation:
 One possible increasing subsequence is: [1, 2, 4, 5, 8]. One possible decreasing subsequence is: [7, 6, 3, 2, 1]. The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.


### Input:
 arr[] = [1, 4, 2, 3, 3, 2, 4]


### Output:
 0


### Explanation:
 One possible increasing subsequence is: [1, 2, 3, 4]. One possible decreasing subsequence is: [4, 3, 2]. All elements are included in one of the two subsequences.


### Constraints:
1 ≤ n ≤ 1001 ≤ arr[i] ≤ 100

---

### 🏢 Topic Tags

> `Dynamic Programming` `Arrays`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>