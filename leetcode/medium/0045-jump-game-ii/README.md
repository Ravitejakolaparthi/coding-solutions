# Jump Game II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **0-indexed**  array of integers `nums` of length `n`. You are initially positioned at index 0.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at index `i`, you can jump to any index `(i + j)` where:

- 0 <= j <= nums[i] and
- i + j < n

Return  *the minimum number of jumps to reach index* `n - 1`. The test cases are generated such that you can reach index `n - 1`.

 

 **Example 1:** 

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

```

 **Example 2:** 

```
Input: nums = [2,3,0,1,4]
Output: 2

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- 0 <= nums[i] <= 1000
- It's guaranteed that you can reach nums[n - 1].

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-08-08T06:14:02.025Z  

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int can_go = nums[0];
        int Jumps = 0;
        for(int i = 1;i<nums.size();i++){
            if(can_go < nums.size()-1)
            {
                Jumps++;
            }
            can_go = max(can_go,i+nums[i]);
        }
        return Jumps;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/jump-game-ii/)