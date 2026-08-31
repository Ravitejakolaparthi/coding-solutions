# Squares of a Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums` sorted in  **non-decreasing**  order, return  *an array of  **the squares of each number**  sorted in non-decreasing order*.

 

 **Example 1:** 

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

```

 **Example 2:** 

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums is sorted in non-decreasing order.

 

 **Follow up:**  Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 41.99%)  
**Memory:** 31.2 MB (beats 23.70%)  
**Submitted:** 2026-08-31T15:53:12.505Z  

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> a;
      int n = nums.size();
      int min = 999999;
      int minidx = -1;
      for(int i = 0;i<n;i++)
      {
        if(nums[i] >= 0 &&  nums[i] < min)
        {
            min = nums[i];
            minidx = i;
        }
      }  
      if(min == 999999)
      {
        minidx = n;
      }
      int j = minidx;
      int i = minidx -1;
      while(i >=0 && j < n)
      {
         if(pow(nums[i],2) > pow(nums[j],2))
         {
            a.push_back(pow(nums[j],2));
            j++;
         }
         else
         {
            a.push_back(pow(nums[i],2));
            i--;
         }
      }
      while(i >= 0)
      {
         a.push_back(pow(nums[i],2));
         i--;
      }
      while(j < n)
      {
        a.push_back(pow(nums[j],2));
        j++;
      }

      return a;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/squares-of-a-sorted-array/)