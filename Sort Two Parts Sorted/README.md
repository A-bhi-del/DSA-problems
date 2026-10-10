# 🚀 Sort Two Parts Sorted

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟢 ![Easy](https://img.shields.io/badge/Easy-success?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/sort-the-half-sorted2157/1) |

---

### 📝 Problem Statement

Given an integer array arr[] where the two parts around a break point are individually sorted, merge them into a single sorted array.  The break point can be anywhere in the array, including at the beginning or end.Examples:

### Input:
 arr[] = [2, 3, 8, -1, 7, 10]


### Output:
 [-1, 2, 3, 7, 8, 10] 


### Explanation:
 [2, 3, 8] and [-1, 7, 10] are sorted in the original array. The overall sorted version is [-1 2 3 7 8 10].

### Input:
 arr[] = [-4, 6, 9, -1, 3]


### Output:
 [-4, -1, 3, 6, 9]


### Explanation:
 [-4, 6, 9] and [-1, 3] are sorted in the original array. The overall sorted version is [-4 -1 3 6 9].

### Input:
 arr[] = [10, 20, 30]


### Output:
 [10, 20, 30]


### Explanation:
 One part is empty and the other part is whole array which is already sorted.

---

### 🏢 Topic Tags

> `two-pointer-algorithm` `Sorting`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>