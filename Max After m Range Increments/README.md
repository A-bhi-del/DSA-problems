# 🚀 Max After m Range Increments

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/max-value-after-m-range-operation4300/1) |

---

### 📝 Problem Statement

Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n, where all elements of arr[] are initially 0.

Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j ≤ b[i] (mainly indexes in range from a[i] to b[i])
After performing all the given operations, find the maximum value present in the array.

Examples:


### Input:
 n = 5, a[] = [0, 1, 2], b[] = [1, 4, 3], k[] = [100, 100, 100]


### Output:
 200


### Explanation:
 Initially, arr = [0, 0, 0, 0, 0]
After the first operation: arr = [100, 100, 0, 0, 0]
After the second operation: arr = [100, 200, 100, 100, 100]
After the third operation: arr = [100, 200, 200, 200, 100]
The maximum element after all operations is 200.


### Input:
 n = 4, a[] = [1, 0, 3], b[] = [2, 0, 3], k[] = [603, 286, 882]


### Output:
 882


### Explanation:
 Initially, arr = [0, 0, 0, 0]
After the first operation: arr = [0, 603, 603, 0]
After the second operation: arr = [286, 603, 603, 0]
After the third operation: arr = [286, 603, 603, 882]
The maximum element after all operations is 882.


### Constraints:
1 ≤  n ≤ 1061 ≤  a.size() = b.size() = k.size() = m  ≤ 1060 ≤  ai  ≤  bi  ≤ n-10 ≤  ki  ≤ 106

---

### 🏢 Topic Tags

> `prefix-sum` `Arrays` `Mathematical`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>