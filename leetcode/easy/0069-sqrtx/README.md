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
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-08-09T04:45:56.088Z  

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 2)
        return x;
        int l = 0;
        int h = x/2;
        int ans =0;
        while(l<=h)
        {
            ans = l+(h-l)/2;
            if(ans == x/ans){
                return ans;
            }
            if(ans > x/ans){
                h = ans-1;
            }
            if(ans < x/ans){
                l = ans+1;
            }
        }
        return ans-1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sqrtx/)