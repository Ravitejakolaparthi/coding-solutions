# Q1. Largest Integer With Given Digit Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given two non-negative integers `n` and `s`.

Return the  **largest**  integer that has  **at most**  `n` digits and whose sum of digits is `s`. If no such integer exists, return -1.

 

 **Example 1:** 

 **Input:**  n = 2, s = 9

 **Output:**  90

 **Explanation:** 

The largest integer with at most 2 digits that has a sum of digits of 9 is 90.

 **Example 2:** 

 **Input:**  n = 2, s = 19

 **Output:**  -1

 **Explanation:** 

There is no integer with at most 2 digits that has a sum of digits of 19, so the answer is -1.

 **Example 3:** 

 **Input:**  n = 5, s = 0

 **Output:**  0

 **Explanation:** 

The only non-negative integer whose digits sum to 0 is 0.

 

 **Constraints:** 

- 1 <= n <= 5
- 0 <= s <= 100

## Solution

**Language:** C++  
**Runtime:** 42 ms  
**Memory:** 8.4 MB (beats 37.50%)  
**Submitted:** 2026-07-26T02:48:10.012Z  

```cpp
class Solution {
public:
    vector<int>v = {0,10,100,1000,10000,100000};
    int digitsum(int x)
    {
        int rem = 0;
        int sum = 0;
        while(x > 0)
            {
                rem = x%10;
                sum += rem;
                x/=10;
            }
        return sum;
    }
    int m = 0;
    int largestInteger(int n, int s) {
        if(s == 0)
            return 0;
        for(int i = v[n-1];i <=v[n]-1;i++)
            {
                int res = digitsum(i);
                if(res == s)
                    m = max(i,m);
                    
            }
        if(m == 0)
        return -1;
        else 
        return m;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/largest-integer-with-given-digit-sum/)