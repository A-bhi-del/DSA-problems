# 🚀 Minimize Max Min Diff with Subarray Removal

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/minimize-the-difference/1) |

---

### 📝 Problem Statement

You are given an array arr[] of size n. You need to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized. Find the minimum value obtained after performing the operation of the removal of the subarray.Examples:

### Input:
 arr = [1, 2, 3, 4, 5], k = 3 

### Output:
 1

### Explanation:
 We remove first subarray of length 3, the remaining array is [4,5] and the difference of maximum and minimum element is 1 i.e 5 - 4 = 1

### Input:
 arr = [2, 3, 1, 4, 6, 7], k = 3

### Output:
 2

### Explanation:
 If we remove the subarray [2,3,1] then remaining array is [4,6,7] and the difference  = 7-4 = 3If we remove the subarray [3,1,4] then remaining array is [2,6,7] and the difference  = 7-2 = 5If we remove the subarray [1,4,6] then remaining array is [2,3,7] and the difference  = 7-2 = 5If we remove the subarray [4,6,7] then remaining array is [2,3,1] and the difference  = 3-1 = 2So the answer is min(3,5,5,2) = 2

---

### 🏢 Topic Tags

> `Arrays` `Prefix Sum`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>