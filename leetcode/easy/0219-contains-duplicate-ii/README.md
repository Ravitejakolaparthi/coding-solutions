# Contains Duplicate II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums` and an integer `k`, return `true`  *if there are two  **distinct indices*** `i` *and* `j` *in the array such that* `nums[i] == nums[j]` *and* `abs(i - j) <= k`.

 

 **Example 1:** 

```
Input: nums = [1,2,3,1], k = 3
Output: true

```

 **Example 2:** 

```
Input: nums = [1,0,1,1], k = 1
Output: true

```

 **Example 3:** 

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109
- 0 <= k <= 105

## Solution

**Language:** C++  
**Runtime:** 321 ms (beats 5.04%)  
**Memory:** 215.7 MB (beats 5.10%)  
**Submitted:** 2026-09-21T05:03:29.338Z  

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for (auto x : mp) {
            for (int i = 1; i < x.second.size(); i++) {
                if(abs(x.second[i] - x.second[i-1])<= k){
                    return true;
                }
            }
        }
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/contains-duplicate-ii/)