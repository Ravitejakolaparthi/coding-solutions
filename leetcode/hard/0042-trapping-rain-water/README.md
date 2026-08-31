# Trapping Rain Water

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

 

 **Example 1:** 

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

 **Example 2:** 

```
Input: height = [4,2,0,3,2,5]
Output: 9

```

 

 **Constraints:** 

- n == height.length
- 1 <= n <= 2 * 104
- 0 <= height[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 27.4 MB (beats 6.02%)  
**Submitted:** 2026-08-31T15:54:33.578Z  

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
                   int drops = 0;
          int n = height.size();
          vector<int> r(n);
          int rm = -1;
          for(int i = n-1;i>=0;i--)
          {
              if(height[i] > rm)
              {
                  rm = height[i];
                  r[i] = height[i];
              }
              else
              {
                  r[i] = rm;
              }
          }
          vector<int>l(n);
          int lm = -1;
          for(int i = 0;i<n;i++)
          {
              if(height[i] > lm)
              {
                  lm = height[i];
                  l[i] = height[i];
              }
              else
              {
                  l[i] = lm;
              }
          }
          
          for(int i = 0;i<n;i++)
          {
              drops += min(l[i],r[i]) - height[i];
          }
        
    
    return drops;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/trapping-rain-water/)