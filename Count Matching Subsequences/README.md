# Count Matching Subsequences

## Problem Link

https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

## Problem Statement

Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
Return the total count modulo 1e9+7.
Examples :


### Input:
 s1 = "geeksforgeeks", s2 = "gks"


### Output:
 4


### Explanation:
 We can pick characters from s1 as a subsequence from indices [0, 3, 4], [0, 3, 12], [0, 11, 12] and [8, 11, 12]. So total 4 subsequences of s1 that are equal to s2.


### Input:
 s1 = "problemoftheday", s2 = "geek"

### Output:
 0

### Explanation:
 No subsequence of string s1 is equal to string s2.


### Constraints:
1 ≤ s1.size(), s2.size() ≤ 103

---

## Solution

See `solution.cpp`
