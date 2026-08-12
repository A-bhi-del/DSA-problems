# 🚀 Adventure in a Maze

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🔴 ![Hard](https://img.shields.io/badge/Hard-critical?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/adventure-in-a-maze2051/1) |

---

### 📝 Problem Statement

Given a maze represented as an n x n grid, grid[][], using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:

1 - you may move Right only.
2 - you may move Down only.
3 - you may move Right or Down (both directions are available).

You start at the top-left cell (0, 0) (the Entry) and must reach the bottom-right cell (n-1, n-1) (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.
The Adventure of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).
Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as [totalPaths, maxAdventure].
Note: Return totalPaths modulo 109 + 7, maxAdventure needs no modulo, as it stays small regardless of grid size.
Examples:


### Input:
 grid[][] = [[3, 2], [1, 3]]


### Output:
 [2, 8]


### Explanation:

There are 2 valid paths from [0, 0] to [1, 1]:
Path 1: [0, 0] -> [0, 1] -> [1, 1], values 3 + 2 + 3 = 8
Path 2: [0,0] -> [1, 0] -> [1, 1], values 3 + 1 + 3 = 7
The maximum Adventure among these is 8, so the output is [2, 8].


### Input:
 grid[][] = [[1, 1, 3, 2, 1], [3, 2, 2, 1, 2], [1, 3, 3, 1, 3], [1, 2, 3, 1, 2], [1, 1, 1, 3, 1]]


### Output:
 [4, 18]


### Explanation:
 There are 4 valid paths from Entry to Exit, with total Adventures 
18, 17, 17, and 16 respectively. The maximum among these is 18, so the output is [4, 18].



### Constraints:
1 ≤ n ≤ 100

---

### 🏢 Topic Tags

> `Dynamic Programming` `Matrix`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>