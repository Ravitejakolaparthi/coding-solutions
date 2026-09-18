# Minimum Size Subarray Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of positive integers `nums` and a positive integer `target`, return  *the  **minimal length**  of a  **subarray**  whose sum is greater than or equal to*  `target`. If there is no such subarray, return `0` instead.

 

 **Example 1:** 

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

```

 **Example 2:** 

```
Input: target = 4, nums = [1,4,4]
Output: 1

```

 **Example 3:** 

```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

```

 

 **Constraints:** 

- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

 

 **Follow up:**  If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 8.50%)  
**Memory:** 41.8 MB (beats 73.86%)  
**Submitted:** 2026-09-18T17:06:35.799Z  

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int i = 0;
        int n  = nums.size();
        int j = 0;
        int ans = 9999999;
        for(int l = 0;l<n;l++){
            sum+=nums[l];
        }
        if(sum<target) return 0;
        sum = 0;
        while(j < n){
            sum += nums[j];
                j++;
               while (sum >= target) {
                    ans = min(ans, j - i);
                    sum -= nums[i];
                    i++;
                }
                
            }
        
        return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)