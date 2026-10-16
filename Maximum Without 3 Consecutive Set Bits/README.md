# 🚀 Maximum Without 3 Consecutive Set Bits

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/geek-hates-too-many-1s--170647/1) |

---

### 📝 Problem Statement

Given a non-negative integer n, you can only change a set bit (1) to an unset bit (0). Find the maximum possible value of n such that its binary representation does not contain three consecutive set bits (111) after performing zero or more allowed operations.Examples:

### Input:
 n = 2


### Output:
 2


### Explanation:
 The binary representation of 2 is 10, which does not contain three consecutive set bits. Therefore, no change is required.

### Input:
 n = 7


### Output:
 6


### Explanation:
 The binary representation of 7 is 111, which contains three consecutive set bits. Changing the rightmost set bit to 0 gives: 111 -> 110. Thus, the maximum possible value is 6.

---

### 🏢 Topic Tags

> `Bit Magic`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>