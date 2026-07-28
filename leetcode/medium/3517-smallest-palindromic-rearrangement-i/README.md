# Smallest Palindromic Rearrangement I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **palindromic**  string `s`.

Return the  **lexicographically smallest**  palindromic permutation of `s`.

 

 **Example 1:** 

 **Input:**  s = "z"

 **Output:**  "z"

 **Explanation:** 

A string of only one character is already the lexicographically smallest palindrome.

 **Example 2:** 

 **Input:**  s = "babab"

 **Output:**  "abbba"

 **Explanation:** 

Rearranging `"babab"` → `"abbba"` gives the smallest lexicographic palindrome.

 **Example 3:** 

 **Input:**  s = "daccad"

 **Output:**  "acddca"

 **Explanation:** 

Rearranging `"daccad"` → `"acddca"` gives the smallest lexicographic palindrome.

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- s is guaranteed to be palindromic.

## Solution

**Language:** C++  
**Runtime:** 199 ms (beats 5.05%)  
**Memory:** 61.9 MB (beats 75.38%)  
**Submitted:** 2026-07-28T03:09:52.916Z  

```cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(int i = 0;i<s.length();i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = 1;
            }
            else
            {
                mp[s[i]]++;
            }
        }
        string s1(s.length(),' ');
        int left = 0;
        int right = s.length() - 1;
        for(auto& i : mp)
        {
            
            while(i.second >= 2) 
            {
                s1[left] = i.first;
                s1[right] = i.first;
                left++;
                right--;
                i.second -= 2; 
            }
        }

        for(auto& i : mp)
        {
            if(i.second > 0)
            {
                s1[left] = i.first; 
                i.second = 0;
                // break;
            }
        }
        return s1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/)