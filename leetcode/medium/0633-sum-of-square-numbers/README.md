# Sum of Square Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

 

 **Example 1:** 

```
Input: c = 5
Output: true
Explanation: 1  *1 + 2*  2 = 5

```

 **Example 2:** 

```
Input: c = 3
Output: false

```

 

 **Constraints:** 

- 0 <= c <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.7 MB  
**Submitted:** 2026-07-29T08:48:49.716Z  

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = c-1;
        while(i < j)
        {
            if(i*i + j*j == c)
            return true;
            else if(i*i + j*j > c)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-square-numbers/)