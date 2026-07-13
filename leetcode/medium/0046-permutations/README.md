# Permutations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

 **Example 2:** 

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]

```

 **Example 3:** 

```
Input: nums = [1]
Output: [[1]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10
- All the integers of nums are unique.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 25.99%)  
**Memory:** 11 MB (beats 20.50%)  
**Submitted:** 2026-07-13T06:41:30.346Z  

```cpp
class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<bool>&v,vector<int>&t)
    {
        if(t.size() == n.size())
        {
            b.push_back(t);
            return ;
        }
        else
        {
            for(int i = 0;i<n.size();i++)
            {
                if(v[i] == 0)
                {
                    t.push_back(n[i]);
                    v[i] = 1;
                    solve(n,v,t);
                    v[i] = 0;
                    t.pop_back();
                    // solve(n,v,t);
                } 
                    
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
       vector<int>t;
       vector<bool>visted(n,0);
       solve(nums,visted,t);
       return b;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutations/)