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
**Runtime:** 11 ms (beats 6.18%)  
**Memory:** 60.1 MB (beats 79.54%)  
**Submitted:** 2026-08-03T09:54:03.079Z  

```cpp
class Solution {
public:
    map<int,int>mp;
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        int j = 0;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp[0]>1)
            {
                mp[nums[j]]--;
                j++;
            }
            length = max(i-j+1,length);
        }
        return length-1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)