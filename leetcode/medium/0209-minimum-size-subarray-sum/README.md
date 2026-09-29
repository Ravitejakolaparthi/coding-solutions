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
**Runtime:** 3 ms (beats 15.90%)  
**Memory:** 41.8 MB (beats 97.56%)  
**Submitted:** 2026-09-29T12:16:10.780Z  

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int size = nums.size()+1;
        int back = 0 , front = 0;
        while(front < nums.size()){
            sum += nums[front];
            while(sum >= target){
                size = min(size,abs(front-back+1));
                sum-=nums[back];
                back++; 
            }
            front++;
        }
        if(size == nums.size()+1) return 0;
        else
        return size;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)