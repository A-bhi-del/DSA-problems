# 🚀 Longest Matching in Dictionary with Removals

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/find-largest-word-in-dictionary2430/1) |

---

### 📝 Problem Statement

Given a lowercase string s and a dictionary d[] containing lowercase words, find the longest word in the dictionary that can be obtained by deleting some characters from s without changing the order of the remaining characters.Note: If multiple words have the same maximum length, return the lexicographically smallest one. If no valid word exists, return an empty string.Examples : 

### Input:
 d = ["ale", "apple", "monkey", "plea"], s = "abpcplea"

### Output:
 "apple" 

### Explanation:
 After deleting "b", "c", "a" s became "apple" which is present in d.


### Input:
 d = ["a", "b", "c"], s = "abpcplea"

### Output:
 "a"

### Explanation:
 After deleting "b", "p", "c", "p", "l", "e", "a" s became "a" which is present in d.

### Constraints:
1 ≤ |s| ≤ 5 * 1051 ≤ n ≤ 104, where n is the number of words in dictionary1 ≤ m ≤ 100, where m is the length of word in dictionarys and all words in dictionary consist only of lowercase English letters.

---

### 🏢 Topic Tags

> `Strings`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>