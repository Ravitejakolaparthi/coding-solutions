# Subarray Sum Equals K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `nums` and an integer `k`, return  *the total number of subarrays whose sum equals to*  `k`.

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [1,1,1], k = 2
Output: 2

```

 **Example 2:** 

```
Input: nums = [1,2,3], k = 3
Output: 2

```

 

 **Constraints:** 

- 1 <= nums.length <= 2 * 104
- -1000 <= nums[i] <= 1000
- -107 <= k <= 107

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-09-05T05:53:50.793Z  

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        int count  = 0;
        for(int i = 0;i<nums.size();i++){
            if(prefix[i] == k)
            count++;
        }
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(prefix[i]-prefix[j] == k)
                count++;
            }
        }
            return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/)