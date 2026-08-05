# Sliding Window Maximum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return  *the max sliding window*.

 

 **Example 1:** 

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

 **Example 2:** 

```
Input: nums = [1], k = 1
Output: [1]

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- 1 <= k <= nums.length

## Solution

**Language:** C++  
**Runtime:** 82 ms (beats 10.19%)  
**Memory:** 150.3 MB (beats 18.08%)  
**Submitted:** 2026-08-05T13:27:49.178Z  

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        for(int i =0;i<k;i++)
        {
            pq1.push(nums[i]);
        }
        vector<int>v;
        v.push_back(pq1.top());
        for(int i=k;i<nums.size();i++)
        {
            pq2.push(nums[i-k]);
            // if()
            pq1.push(nums[i]);
            while(!pq1.empty() && !pq2.empty() && pq1.top() == pq2.top())
            {
                pq1.pop();
                pq2.pop();
            }
            v.push_back(pq1.top());
        }
        // 1 3 -1 -3 5 3 6 7
            return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sliding-window-maximum/)