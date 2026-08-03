# Longest Subarray of 1's After Deleting One Element

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary array `nums`, you should delete one element from it.

Return  *the size of the longest non-empty subarray containing only* `1` *'s in the resulting array*. Return `0` if there is no such subarray.

 

 **Example 1:** 

```
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

```

 **Example 2:** 

```
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

```

 **Example 3:** 

```
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 60.1 MB (beats 50.02%)  
**Submitted:** 2026-08-03T09:38:22.944Z  

```cpp
class Solution {
public:
    int expand(int idx,vector<int>&nums)
    {
        int count = 0;
        int idxcopy = idx;
        idx++;
        while(idx <nums.size() && nums[idx] !=0)
        {
            if(nums[idx] == 1)
            count++;
            idx++;
        }
        idx = idxcopy;
        idx--;
        while(idx>=0 && nums[idx]!=0)
        {
            if(nums[idx] == 1)
            count++;
            idx--;
        }
        return count;
    }
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        for(int i =0;i<nums.size();i++) if(nums[i] == 0) length++;
        if(length == 0) return nums.size()-1;
        length = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                length = max(length,expand(i,nums));
            }
        }
        return length;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)