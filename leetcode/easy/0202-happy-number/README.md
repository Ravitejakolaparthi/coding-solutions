# Happy Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write an algorithm to determine if a number `n` is happy.

A  **happy number**  is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.

Return `true`  *if*  `n`  *is a happy number, and*  `false`  *if not*.

 

 **Example 1:** 

```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

```

 **Example 2:** 

```
Input: n = 2
Output: false

```

 

 **Constraints:** 

- 1 <= n <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-07-06T14:01:02.639Z  

```cpp
class Solution {
public:
    int digitsum(int n)
    {
        int rem = 0;
        int sum = 0;
        while(n>0)
        {
            rem = n%10;
            sum += pow(rem,2);
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {
            unordered_set<int>s;
            s.insert(n);
            while(n!=1)
            {
                n = digitsum(n);
                if(s.find(n)==s.end())
                {
                    s.insert(n);
                }
                else
                {
                    return false;
                }
            }  
            return true;  
        }
         
};
```

---

[View on LeetCode](https://leetcode.com/problems/happy-number/)