# Sqrt(x)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a non-negative integer `x`, return  *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be  **non-negative**  as well.

You  **must not use**  any built-in exponent function or operator.

- For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

 **Example 1:** 

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

```

 **Example 2:** 

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

```

 

 **Constraints:** 

- 0 <= x <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.5 MB (beats 87.93%)  
**Submitted:** 2026-08-09T04:51:46.992Z  

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
        return x;
        int l = 1;
        int h = x/2;
        int ans =0;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(mid == x/mid){
                return mid;
            }
            else if(mid > x/mid){
                h = mid-1;
            }
            if(mid < x/mid){
                  ans = mid;
                l = mid+1;
              
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sqrtx/)