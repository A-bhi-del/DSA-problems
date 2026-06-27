# Ways to Tile the Floor

## Problem Link

https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1

## Problem Statement

Given a floor of dimensions n × m and an unlimited supply of tiles of size 1 × m, find the total number of ways to completely tile the floor.Each tile can be placed in one of the following ways:

Horizontally, covering 1 row and m columns.
Vertically, covering m rows and 1 column.

Count all possible ways to cover the entire floor such that there are no overlaps and no uncovered cells.
Since the number of possible tilings can be very large, return the answer modulo 109+7.
Note: n and m are positive integers, and m ≥ 2.
Examples:


### Input:
 n = 4, m = 4


### Output:
 2


### Explanation:
 There are exactly two valid ways to tile the floor. 


### Input:
 n = 2, m = 3


### Output:
 1


### Explanation:
 Placing a tile vertically would require a height of 3, which exceeds the floor's height of 2. The only way to cover the entire floor is by placing 2 horizontally, one in each row, resulting in exactly one valid tiling. 


### Constraints:
1 ≤ n ≤ 1052 ≤ m ≤ 105

---

## Solution

See `solution.cpp`
