# 🚀 Largest with Same Parity Adjacent Swaps

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/even-swap/1) |

---

### 📝 Problem Statement

Given an array arr[], you are allowed to swap two adjacent elements, arr[i] and arr[i + 1] only if their sum is even. Find the lexicographically largest array that can be obtained by performing this operation any number of times, including zero times. Note: An array X is lexicographically larger than another array Y if, at the first position where they differ, X has the larger element.Examples:

### Input:
 arr[] = [1, 3, 5]

### Output:
 [5, 3, 1]


### Explanation:
 We can swap any adjacent pair as all have even sum. All possible obtainable arrays are [1, 3, 5], [1, 5, 3], [3, 1, 5], [3, 5, 1], [5, 1, 3] and [5, 3, 1] The array [5, 3, 1] is lexicographically largest.

### Input:
 arr[] = [1, 3, 4, 2]


### Output:
 [3, 1, 4, 2]

### Explanation:
 [1, 3, 4, 2], [1, 3, 2, 4], [3, 1, 2, 4] and [3, 1, 4, 2] are all possible, among which the last one is lexicographically largest one.

---

### 🏢 Topic Tags

> `Arrays` `Sorting`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>