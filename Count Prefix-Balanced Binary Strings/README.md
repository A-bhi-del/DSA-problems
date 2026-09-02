# 🚀 Count Prefix-Balanced Binary Strings

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1) |

---

### 📝 Problem Statement

Given an integer n, count the number of binary strings of length 2 × n that contain exactly n ones and n zeros, such that in every prefix of the string, the number of ones is greater than or equal to the number of zeros.
A prefix is any substring that starts from the first character of the string and ends at any position. Return the count modulo 10^9 + 7.
Examples:


### Input:
 n = 2


### Output:
 2


### Explanation:
 The two valid strings are "1100" and "1010".
For "1100", every prefix has at least as many ones as zeros:
"1" -> 1 one, 0 zeros
"11" -> 2 ones, 0 zeros
"110" -> 2 ones, 1 zero
"1100" -> 2 ones, 2 zeros
Similarly, "1010" also satisfies the condition for every prefix. Therefore, the answer is 2.


### Input:
 n = 3


### Output:
 5


### Explanation:
 The five valid strings are "111000", "110100", "110010", "101100", and "101010".
For example, consider "110100":
"1" -> 1 one, 0 zeros
"11" -> 2 ones, 0 zeros
"110" -> 2 ones, 1 zero
"1101" -> 3 ones, 1 zero
"11010" -> 3 ones, 2 zeros
"110100" -> 3 ones, 3 zeros
The condition is satisfied for every prefix. All five listed strings satisfy the same condition, so the answer is 5.

---

### 🏢 Topic Tags

> `Dynamic Programming`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>