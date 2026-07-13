# Combination Sum II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used  **once**  in the combination.

 **Note:**  The solution set must not contain duplicate combinations.

 

 **Example 1:** 

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

 **Example 2:** 

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```

 

 **Constraints:** 

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 9.9 MB  
**Submitted:** 2026-07-13T04:44:49.851Z  

```cpp
class Solution {
public:
    vector<vector<int>>b;
    void move(vector<int>&n,int s,vector<int>v,int i)
    {
        if(s >= 0 && i < n.size())
        {
            if(s == 0)
            {
                
                b.push_back(v);
            }
            else
            {
                move(n,s,v,i+1);
                v.push_back(n[i]);
                move(n,s-n[i],v,i+1);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<int>v;
     sort(candidates.begin(),candidates.end());
     move(candidates,target,v,0);
     set<vector<int>>s(b.begin(),b.end());
     vector<vector<int>>res(s.begin(),s.end());
     return res;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)