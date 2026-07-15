# Letter Combinations of a Phone Number

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in  **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

 **Example 1:** 

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

```

 **Example 2:** 

```
Input: digits = "2"
Output: ["a","b","c"]

```

 

 **Constraints:** 

- 1 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.6 MB (beats 21.10%)  
**Submitted:** 2026-07-15T09:15:42.540Z  

```cpp
class Solution {
public:
    map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tvu"},{'9',"wxyz"}};
    vector<string>v;
    void solve(int i,string digits,string str)
    {
        // cout << 1;
        
            // cout << 1;
            if(i==digits.size())
            {
              v.push_back(str);
              return ;   
            }
            else
            {
                   
                string t = mp[digits[i]];
                // cout << t;
                for(int j = 0;j<t.size();j++)
                {
                    str.push_back(t[j]);
                    // cout << str <<endl;
                    solve(i+1,digits,str);
                    str.pop_back();
                }
            }
        
    }
    vector<string> letterCombinations(string digits) {
        string str;
        solve(0,digits,str);
        return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)