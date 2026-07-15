# 🚀 Longest Bitonic Subarray

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1) |

---

### 📝 Problem Statement

Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.
A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists and index k (where i <= k <= j) such that:

arr[i] <= arr[i+1] <= . . . <= arr[k] 
arr[k] >= arr[k+1] >= . . . >= arr[j]

Examples: 


### Input:
 arr[] = [12, 4, 78, 90, 45, 23]


### Output:
 5


### Explanation:
 The longest bitonic subarray is [4, 78, 90, 45, 23], it starts increasing at 4, peaks at 90, and decreases to 23, giving length of 5.


### Input:
 arr[] = [10, 20, 30, 40]


### Output:
 4


### Explanation:
 The array [10, 20, 30, 40] is striclty increasing with no decreasing part, so longest bitonic subarray is the entire array itself, giving a length of 4.


### Input:
 arr[] = [10, 10, 10, 10]


### Output:
 4


### Constraints:
1 ≤  n ≤ 1061 ≤ arr[i] ≤ 106

---

### 🏢 Topic Tags

> `Arrays` `Data Structures`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>