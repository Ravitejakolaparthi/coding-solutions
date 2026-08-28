# Remove All Adjacent Duplicates In String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given a string `s` consisting of lowercase English letters. A  **duplicate removal**  consists of choosing two  **adjacent**  and  **equal**  letters and removing them.

We repeatedly make  **duplicate removals**  on `s` until we no longer can.

Return  *the final string after all such duplicate removals have been made*. It can be proven that the answer is  **unique**.

 

 **Example 1:** 

```
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

```

 **Example 2:** 

```
Input: s = "azxxzy"
Output: "ay"

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 56.05%)  
**Memory:** 14.4 MB (beats 35.04%)  
**Submitted:** 2026-08-28T04:43:04.013Z  

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        // string s;
        string ans;
        stack<char>st;
        st.push(s[0]);
        for(int i = 1;i<s.length();i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
            while(!st.empty()){
                char x = st.top();
                ans += x;
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)