# Range Sum Query - Immutable

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer array `nums`, handle multiple queries of the following type:

- Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the `NumArray` class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +... + nums[right]).

 

 **Example 1:** 

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- -105 <= nums[i] <= 105
- 0 <= left <= right < nums.length
- At most 104 calls will be made to sumRange.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 23.9 MB (beats 95.15%)  
**Submitted:** 2026-08-05T19:05:27.657Z  

```cpp
class NumArray {
public:
    // vector<int>nums;
    vector<int>p;
    NumArray(vector<int>& nums) {
        // this ->nums = nums;
        
        p.resize(nums.size());
        p[0]=nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            p[i] = p[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // int sum=0; 
       
        if(left > 0)
        return p[right] - p[left-1];
        else
        return p[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```

---

[View on LeetCode](https://leetcode.com/problems/range-sum-query-immutable/)