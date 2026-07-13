# Subsets II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` that may contain duplicates, return  *all possible*   *subsets** (the power set)*.

The solution set  **must not**  contain duplicate subsets. Return the solution in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

```

 **Example 2:** 

```
Input: nums = [0]
Output: [[],[0]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 6.14%)  
**Memory:** 17.7 MB (beats 5.03%)  
**Submitted:** 2026-07-13T02:04:24.029Z  

```cpp
class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>v,int i)
    {
        if(i == n.size())
        {
            sort(v.begin(),v.end());
            b.push_back(v);
        }
        else
        {
            solve(n,v,i+1);
            v.push_back(n[i]);
            solve(n,v,i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>u;
       solve(nums,u,0);
       set<vector<int>>s(b.begin(),b.end());
       vector<vector<int>>v(s.begin(),s.end()); 
       return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subsets-ii/)