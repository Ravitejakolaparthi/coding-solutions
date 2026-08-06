# Maximum Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, find the subarray with the largest sum, and return  *its sum*.

 

 **Example 1:** 

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

```

 **Example 2:** 

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

```

 **Example 3:** 

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

 

 **Follow up:**  If you have figured out the `O(n)` solution, try coding another solution using the  **divide and conquer**  approach, which is more subtle.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 21.35%)  
**Memory:** 71.9 MB (beats 15.18%)  
**Submitted:** 2026-08-06T09:51:01.653Z  

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int curr= nums[0];
            int maxi = nums[0];
            for(int i = 1;i<nums.size();i++)
            {
                curr = max(nums[i],curr+nums[i]);
                maxi = max(curr,maxi);
            }
            return maxi;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-subarray/)