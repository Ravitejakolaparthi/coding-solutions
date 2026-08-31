# Find First and Last Position of Element in Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 

 **Example 1:** 

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

```

 **Example 2:** 

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

 **Example 3:** 

```
Input: nums = [], target = 0
Output: [-1,-1]

```

 

 **Constraints:** 

- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109
- nums is a non-decreasing array.
- -109 <= target <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17.4 MB (beats 99.62%)  
**Submitted:** 2026-08-31T15:50:23.179Z  

```cpp
class Solution {
public:
    bool check1(int limit,int target,vector<int>&nums){
            if(nums[limit]  == target)
            return true;
            return false;
    }

    int solve1(int high,int target,vector<int>&nums){
        int low = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check1(mid,target,nums)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    int solve2(int low,int target,vector<int>&nums){
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check1(mid,target,nums)){
                low = mid + 1;
            }
            else{
                // low = mid + 1;
                high = mid - 1;
            }
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int low = 0;
        int high = nums.size()-1;
        vector<int>v = {-1,-1};
        // 5 7 7 8 8 10
        // 0 1 2 3 4 5
        while(low <= high){
            int  mid = low + (high-low)/2;
            if(nums[mid]== target){
                    v[0] = solve1(mid,target,nums);
                    v[1] = solve2(mid,target,nums);
                    return v;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)