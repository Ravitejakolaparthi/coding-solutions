# Factorial

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given a positive integer,  **n**. Find the factorial of  **n**.

 **Examples :** 

```
Input: n = 5
Output: 120
Explanation: 1 x 2 x 3 x 4 x 5 = 120
```

```
Input: n = 4
Output: 24
Explanation: 1 x 2 x 3 x 4 = 24
```

 **Constraints:** 
0 ≤ n ≤ 12

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-05T16:17:42.419Z  

```cpp
class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n == 0)
        return 1;
        if(n == 1)
        return 1;
        else 
        return n*factorial(n-1);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/factorial5739/1)