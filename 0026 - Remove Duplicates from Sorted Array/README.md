## Remove Duplicates from Sorted Array

**Solved**

**Easy**

This document explains how to address the "Remove Duplicates from Sorted Array" problem. It includes a breakdown of the approach and a hint towards the solution code.

**Problem**

Given an integer array `nums` sorted in non-decreasing order, remove duplicates **in-place** such that each unique element appears only once. The relative order of the elements must be preserved. The function should return the number of unique elements found in `nums`.

**Constraints**

* `1 <= nums.length <= 3 * 10^4` (Array size between 1 and 30,000 elements)
* `-100 <= nums[i] <= 100` (Elements range from -100 to 100)
* `nums` is sorted in non-decreasing order

**Hint**

Consider the number of unique elements in `nums` to be `k`. To achieve a successful solution:

1. Modify `nums` such that the first `k` elements contain the unique elements in the order they were initially presented.
2. The remaining elements in `nums` are insignificant, and their exact values or the final array size are not important.
3. Return the value of `k` (number of unique elements).

**Example 1:**

Input: `nums = [1,1,2]`

Output: `2, nums = [1,2,_]`

Explanation: The function should return `2`, with the first two elements of `nums` being `1` and `2`, respectively. The values beyond the second element (represented by underscores) are not crucial.

**Example 2:**

Input: `nums = [0,0,1,1,1,2,2,3,3,4]`

Output: `5, nums = [0,1,2,3,4,_,_,_,_,_]`

Explanation: The function should return `5`, with the first five elements of `nums` being `0`, `1`, `2`, `3`, and `4`, respectively. The values beyond the fifth element are not important.
