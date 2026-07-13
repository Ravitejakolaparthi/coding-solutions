# Subsets

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` of  **unique**  elements, return  *all possible*   *subsets*   *(the power set)*.

The solution set  **must not**  contain duplicate subsets. Return the solution in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

```

 **Example 2:** 

```
Input: nums = [0]
Output: [[],[0]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
- All the numbers of nums are unique.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 27.77%)  
**Memory:** 15.9 MB (beats 5.84%)  
**Submitted:** 2026-07-13T01:39:58.534Z  

```cpp
class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>v,int i)
    {
        if(i == n.size())
        {
            b.push_back(v);
           
        }
        else
        {
            v.push_back(n[i]);
            solve(n,v,i+1);
            v.pop_back();
            solve(n,v,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(nums,v,0);
        return b;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subsets/)