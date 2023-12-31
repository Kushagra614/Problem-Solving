74. Search a 2D Matrix
Solved
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:
![image](https://github.com/Kushagra614/LeetCode-Problems/assets/129066926/df03a8ea-ad55-44d8-9e8b-cdfdc4c59f61)


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

![image](https://github.com/Kushagra614/LeetCode-Problems/assets/129066926/cbf0f11d-bc80-4a7f-8b69-4250d62a2fe0)


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
