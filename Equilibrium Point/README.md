# 🚀 Equilibrium Point

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟢 ![Easy](https://img.shields.io/badge/Easy-success?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&company=Google&sortBy=submissions) |

---

### 📝 Problem Statement

Given an array of integers arr[], the task is to find the first equilibrium point in the array.
The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 
Examples:


### Input:
 arr[] = [1, 2, 0, 3]

### Output:
 2 


### Explanation:
 The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.


### Input:
 arr[] = [1, 1, 1, 1]

### Output:
 -1


### Explanation:
 There is no equilibrium index in the array.


### Input:
 arr[] = [-7, 1, 5, 2, -4, 3, 0]

### Output:
 3


### Explanation:
 The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.


### Constraints:
3 <= arr.size() <= 105-104 <= arr[i] <= 104

---

### 🏢 Topic Tags

> `prefix-sum` `Arrays` `Data Structures` `Algorithms`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>