# Longest Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` which consists of lowercase or uppercase letters, return the length of the  **longest palindrome**  that can be built with those letters.

Letters are  **case sensitive**, for example, `"Aa"` is not considered a palindrome.

 

 **Example 1:** 

```
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

```

 **Example 2:** 

```
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s consists of lowercase and/or uppercase English letters only.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.5 MB (beats 5.50%)  
**Submitted:** 2026-07-30T16:47:00.240Z  

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
        return 1;

        int sum = 0;
        int odd = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<s.size();i++)
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
        int one  = 0;
        int cnt = 0;
        for(auto i = mp.begin();i!=mp.end();i++)
        {
            if(i->second%2 == 0)
            {
            sum+=i->second;
            }
            else
            {
               cnt++;
               odd+=i->second;

            }

        }
        // cnt-=1;
        if(odd > 0)
        {
            return sum + odd-cnt+1;
        }
        else
        {
            return sum;
        }
        





















    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-palindrome/)