# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 70.17%)  
**Memory:** 16 MB (beats 31.98%)  
**Submitted:** 2026-07-14T09:38:51.867Z  

```cpp
class Solution {
public:
    vector<string>s;
    void solve(int o,int c,int n,string curr)
    {
        if(o == n && c == n)
        {
            s.push_back(curr);
        }
        else
        {
            if(o < n)
            {
                solve(o+1,c,n,curr+"(");
            }
            if(o > c)
            {
                solve(o,c+1,n,curr+")");
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(0,0,n,curr);  
        return s;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)