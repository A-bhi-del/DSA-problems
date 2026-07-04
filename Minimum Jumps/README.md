# 🚀 Minimum Jumps

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&company=Google&sortBy=submissions) |

---

### 📝 Problem Statement

You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.
For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.

Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.
Note:  Return -1 if you can't reach the end of the array.
Examples :  


### Input:
 arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]


### Output:
 3 


### Explanation:
 First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 


### Input:
 arr = [1, 4, 3, 2, 6, 7]

### Output:
 2 


### Explanation:
 First we jump from the 1st to 2nd element and then jump to the last element.


### Input:
 arr = [0, 10, 20]

### Output:
 -1


### Explanation:
 We cannot go anywhere from the 1st element.



### Constraints:
2 ≤ arr.size() ≤ 1050 ≤ arr[i] ≤ 105

---

### 🏢 Topic Tags

> `Arrays` `Greedy` `Data Structures` `Algorithms`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>