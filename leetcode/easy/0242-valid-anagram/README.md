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
**Runtime:** 8 ms (beats 7.13%)  
**Memory:** 9.8 MB (beats 49.68%)  
**Submitted:** 2026-07-09T00:47:31.747Z  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s.size()!=t.size())
            return false;
            for(int i = 0;i<s.size();i++)
            {
                if(s[i]!=t[i])
                return false;
            }
            return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-anagram/)