# Concatenate Array With Reverse

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums` of length `n`.

Construct a new array `ans` of length `2 * n` such that the first `n` elements are the same as `nums`, and the next `n` elements are the elements of `nums` in reverse order.

Formally, for `0 <= i <= n - 1`:

- ans[i] = nums[i]
- ans[i + n] = nums[n - i - 1]

Return an integer array `ans`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3]

 **Output:**  [1,2,3,3,2,1]

 **Explanation:** 

The first `n` elements of `ans` are the same as `nums`.

For the next `n = 3` elements, each element is taken from `nums` in reverse order:

- ans[3] = nums[2] = 3
- ans[4] = nums[1] = 2
- ans[5] = nums[0] = 1

Thus, `ans = [1, 2, 3, 3, 2, 1]`.

 **Example 2:** 

 **Input:**  nums = [1]

 **Output:**  [1,1]

 **Explanation:** 

The array remains the same when reversed. Thus, `ans = [1, 1]`.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.1 MB  
**Submitted:** 2026-07-02T14:19:46.942Z  

```cpp
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = 2*nums.size();
        vector<int>v(n);
        for(int i=0;i<nums.size();i++)
        v.push_back(v[i]);
        for(int i=nums.size()-1;i>=0;i--)
        v.push_back(v[i]);
        return v;   
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/concatenate-array-with-reverse/)