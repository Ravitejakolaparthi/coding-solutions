# Letter Case Permutation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, you can transform every letter individually to be lowercase or uppercase to create another string.

Return  *a list of all possible strings we could create*. Return the output in  **any order**.

 

 **Example 1:** 

```
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

```

 **Example 2:** 

```
Input: s = "3z4"
Output: ["3z4","3Z4"]

```

 

 **Constraints:** 

- 1 <= s.length <= 12
- s consists of lowercase English letters, uppercase English letters, and digits.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 32.92%)  
**Memory:** 16.2 MB (beats 7.73%)  
**Submitted:** 2026-07-15T01:18:12.710Z  

```cpp
class Solution {
public:
    vector<string>a;
    void solve(string v,int i)
    {
        if(i == v.size())
        {
            a.push_back(v);
        }
        else
        {
            if(isalpha(v[i]))
            {
                v[i] = tolower(v[i]);
                solve(v,i+1);

                v[i] = toupper(v[i]);
            }
            
            solve(v,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
            solve(s,0);
            return a;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/letter-case-permutation/)