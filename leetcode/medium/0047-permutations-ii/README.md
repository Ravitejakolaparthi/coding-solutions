# Permutations II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of numbers, `nums`, that might contain duplicates, return  *all possible unique permutations  **in any order**.* 

 

 **Example 1:** 

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

```

 **Example 2:** 

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 8
- -10 <= nums[i] <= 10

## Solution

**Language:** C++  
**Runtime:** 83 ms (beats 5.67%)  
**Memory:** 37.1 MB (beats 5.07%)  
**Submitted:** 2026-08-31T15:44:54.374Z  

```cpp
class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>&u,vector<bool>&v)
    {
        if(u.size() == n.size())
        {
            b.push_back(u);
        }
        else
        {
            for(int i = 0;i<n.size();i++)
            {
                if(v[i] == 0)
                {
                    u.push_back(n[i]);
                    v[i] = 1;
                    solve(n,u,v);
                    v[i] = 0;
                    u.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        vector<bool>v(n,0);
        vector<int>u;
        solve(nums,u,v);
        set<vector<int>>s(b.begin(),b.end());
        vector<vector<int>>res(s.begin(),s.end());
        return res;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutations-ii/)