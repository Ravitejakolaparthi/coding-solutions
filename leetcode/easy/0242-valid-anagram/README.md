# Valid Anagram

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  s = "anagram", t = "nagaram"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "rat", t = "car"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

 

 **Follow up:**  What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-07-07T09:13:16.521Z  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        char m = 0;
        for(int i = 0;i<s.size();i++)
        {
            m^= s[i];
            m^=t[i];
        }
        if(m == 0)
        return true;
        else 
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-anagram/)