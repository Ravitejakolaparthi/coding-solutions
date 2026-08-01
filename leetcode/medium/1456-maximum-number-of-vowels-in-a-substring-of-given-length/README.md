# Maximum Number of Vowels in a Substring of Given Length

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s` and an integer `k`, return  *the maximum number of vowel letters in any substring of* `s` *with length* `k`.

 **Vowel letters**  in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

 

 **Example 1:** 

```
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

```

 **Example 2:** 

```
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

```

 **Example 3:** 

```
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- 1 <= k <= s.length

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 37.58%)  
**Memory:** 13.2 MB (beats 28.86%)  
**Submitted:** 2026-08-01T13:04:52.773Z  

```cpp
class Solution {
public:
    int vowel(char n)
    {
        if(n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')
        {
            return 1;
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        int vowels = 0;
        for(int i = 0;i<k;i++)
        {
             vowels+=vowel(s[i]);
        }
        int currvowels = vowels;
        for(int i = k;i<s.size();i++)
        {
            vowels += vowel(s[i]);
            vowels += -1*vowel(s[i-k]);
            currvowels  = max(currvowels,vowels); 
        }
        return currvowels;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)