# Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, find the length of the  **longest**   **substring**  without duplicate characters.

 

 **Example 1:** 

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

```

 **Example 2:** 

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

 **Example 3:** 

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

 

 **Constraints:** 

- 0 <= s.length <= 105
- s consists of English letters, digits, symbols and spaces.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-09-03T17:07:13.805Z  

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n = s.length();
        int k = 0;
        int size = 0;
        int maxsize = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) == mp.end())
            {
                k++;                        // p  w 
                mp[s[i]] = 1;
                size = mp.size();
                maxsize = max(size,maxsize);
            }
            else{
                int j = i;
                while(mp.find(s[i]) != mp.end()){  // p w // w // 0 // w
                    mp.erase(s[j-k]);
                    size = mp.size();
                    maxsize = max(size,maxsize);
                    j++;
                }
                mp[s[i]] = 1;
                size = 0;
            }
        }
        return maxsize;
      
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)