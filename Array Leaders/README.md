# 🚀 Array Leaders

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟢 ![Easy](https://img.shields.io/badge/Easy-success?style=for-the-badge&logoColor=white) |
| **Language** | `Python3` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=1&category=Arrays&sortBy=submissions) |

---

### 📝 Problem Statement

You are given an array `arr` of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

#### Examples:

**Input:**  
`arr = [16, 17, 4, 3, 5, 2]`  
**Output:**  
`[17, 5, 2]`  
**Explanation:**  
Note that there is nothing greater on the right side of 17, 5 and, 2.

**Input:**  
`arr = [10, 4, 2, 4, 1]`  
**Output:**  
`[10, 4, 4, 1]`  
**Explanation:**  
Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right side.

**Input:**  
`arr = [5, 10, 20, 40]`  
**Output:**  
`[40]`  
**Explanation:**  
When an array is sorted in increasing order, only the rightmost element is leader.

**Input:**  
`arr = [30, 10, 10, 5]`  
**Output:**  
`[30, 10, 10, 5]`  
**Explanation:**  
When an array is sorted in non-increasing order, all elements are leaders.

#### Constraints:
* $1 \le \text{arr.size()} \le 10^6$
* $0 \le \text{arr[i]} \le 10^6$

---

### 🏢 Company Tags

> `Arrays` `Data Structures`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized right-to-left scan approach to solve the problem in $O(n)$ time complexity.

👉 **View Solution:** [`solution.py`](./solution.py)

---
<sub>*Automated repository update.*</sub>
