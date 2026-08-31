# 3Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

 

 **Example 1:** 

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

```

 **Example 2:** 

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

```

 **Example 3:** 

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

```

 

 **Constraints:** 

- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 2617 ms (beats 5.02%)  
**Memory:** 447.2 MB (beats 5.14%)  
**Submitted:** 2026-08-31T15:55:34.570Z  

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>a;
             sort(nums.begin(),nums.end());
        int i = 0,j = 1,k = nums.size()-1;
        while(i < k-1)
        {
            while(j < k)
            {
                int b= nums[i]+ nums[j]+nums[k];
                int a1 = nums[i];
                int a2 = nums[j];
                int a3 = nums[k];
                if(b == 0)
                {
                    a.push_back({a1,a2,a3});
                    j++;
                    k--;
                }
                else if(b> 0)
                {
                    k--;
                }
                else if(b< 0)
                {
                    j++;
                }
            }
           
            i++;
            j = i+1;
            k = nums.size()-1;
            
        }
            sort(a.begin(),a.end());
            a.erase(unique(a.begin(),a.end()),a.end());
           return a;
    }
 
};
```

---

[View on LeetCode](https://leetcode.com/problems/3sum/)