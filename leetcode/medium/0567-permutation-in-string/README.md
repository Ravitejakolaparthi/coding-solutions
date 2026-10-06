# Permutation in String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

 

 **Example 1:** 

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

```

 **Example 2:** 

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

```

 

 **Constraints:** 

- 1 <= s1.length, s2.length <= 104
- s1 and s2 consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 435 ms (beats 8.58%)  
**Memory:** 11.3 MB (beats 14.54%)  
**Submitted:** 2026-10-06T15:57:59.379Z  

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int right = 0;
        int left = 0;
        int k = s1.length();
        if (s1.length() > s2.length()) return false;
        map<char,int>window;
        map<char,int>mp;
        for (int i = 0; i < k; i++) {
            window[s2[i]]++;
            mp[s1[i]]++;
            right = i;
        }
        while (right < s2.length()) {
            int count = 0;
            for (char i : s1) {
                if (window.find(i) == window.end()) {
                    window[s2[left]]--;
                    if(window[s2[left]] == 0)
                    window.erase(s2[left]);
                    left++;
                    right++;
                    window[s2[right]]++;
                    break;
                } else {
                    count++;
                }
            }
            if (count == k){
                int flag = 0;
                for(char ch : s1) {
                if (window[ch] != mp[ch])
                {
                    flag = 1;
                    break;
                }
                }

                if (flag == 0) return true;
                    window[s2[left]]--;
                    if(window[s2[left]] == 0)
                    window.erase(s2[left]);
                    left++;
                    right++;
                    window[s2[right]]++;

		     }
        }
        return false;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutation-in-string/)