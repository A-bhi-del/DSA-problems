# 🚀 Range Vowel Count Queries

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/range-vowel-count-queries-static/1) |

---

### 📝 Problem Statement

Given a string s and a 2D array queries[][], where each query consists of two integers l and r, find the number of vowels in the substring s[l....r] for each query. The substring includes both indices l and r. Return an array containing the answers to all queries in the order they are given.Examples:

### Input:
 s = "geeksforgeeks", queries[][] = [[1, 3], [2, 4], [1, 9]]

### Output:
 [2, 1, 4]

### Explanation:
Query 1: "eek" has 2 vowels (e, e).Query 2: "eks" has 1 vowel (e).Query 3: "eeksforge" has 4 vowels (e, e, o, e).

### Input:
 s = "helloworld", queries[][] = [[0, 4], [5, 9], [0, 9]]

### Output:
 [2, 1, 3]

### Explanation:
Query 1: "hello" has 2 vowels (e, o).Query 2: "world" has 1 vowel (o).Query 3: "helloworld" has 3 vowels (e, o, o).

---

### 🏢 Topic Tags

> `Prefix Sum` `Strings`

---

### 💡 Solution File

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Synced automatically with [GFG Sync](https://github.com/)*</sub>