# 🚀 High Effort vs Low Effort

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟢 ![Easy](https://img.shields.io/badge/Easy-success?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/high-effort-vs-low-effort0213/1) |

---

### 📝 Problem Statement

Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on the i-th day by performing a high-effort task and a low-effort task, respectively.
For each day, you may choose exactly one of the following:

Perform no task.
Perform a low-effort task.
Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.

Return the maximum total number of tasks that can be completed over all days.
Examples:


### Input:
 h[] = [2, 8, 1], l[] = [1, 2, 1]


### Output:
 9


### Explanation:
 Pick the high-effort task on day 1 and the low-effort task on day 2. Total = 8 + 1 = 9.


### Input:
 h[] = [3, 6, 8, 7, 6], l[] = [1, 5, 4, 5, 3]


### Output:
 20


### Explanation:
 Pick the high-effort task on day 0 and low-effort tasks on all remaining days. Total = 3 + 5 + 4 + 5 + 3 = 20.

---

### 🏢 Topic Tags

> `Dynamic Programming`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>