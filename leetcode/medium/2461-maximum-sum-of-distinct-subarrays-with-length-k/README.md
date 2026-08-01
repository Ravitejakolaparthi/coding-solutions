# Maximum Sum of Distinct Subarrays With Length K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and an integer `k`. Find the maximum subarray sum of all the subarrays of `nums` that meet the following conditions:

- The length of the subarray is k, and
- All the elements of the subarray are distinct.

Return  *the maximum subarray sum of all the subarrays that meet the conditions**.*  If no subarray meets the conditions, return `0`.

 *A  **subarray**  is a contiguous non-empty sequence of elements within an array.* 

 

 **Example 1:** 

```
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

```

 **Example 2:** 

```
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.

```

 

 **Constraints:** 

- 1 <= k <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 262 ms (beats 5.08%)  
**Memory:** 106.6 MB (beats 5.16%)  
**Submitted:** 2026-08-01T12:37:15.676Z  

```cpp
class Solution {
public:
    map<int,int>mp;
    void mappush(int n)
    {
        if(mp.find(n) == mp.end())
        {
            mp[n] = 1;
        }
        else
        {
            mp[n]++;
        }
    }
    void mappop(int n)
    {
         mp[n]--;
       if(mp[n] == 0)
        mp.erase(n);
        // else/
     
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<k)
        return 0;
        long long sum = 0;
        vector<long long>v ={0};
        for(int i = 0;i<k;i++)
        {
            mappush(nums[i]);
            sum += nums[i];
        }  
        int i = 0;
        int j = k;
        if(mp.size() == k)
        v.push_back(sum);
        while(i < nums.size() && j < nums.size())
        {
            
                sum += nums[j];
                sum -= nums[i];
                mappush(nums[j]);
                mappop(nums[i]);
                i++;
                j++;
                if(mp.size() == k)
                v.push_back(sum);
            
        }
        return *max_element(v.begin(),v.end());
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)