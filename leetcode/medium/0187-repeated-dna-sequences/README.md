# Repeated DNA Sequences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The  **DNA sequence**  is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.

- For example, "ACGAATTCCG" is a DNA sequence.

When studying  **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a  **DNA sequence**, return all the  **`10`-letter-long**  sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in  **any order**.

 

 **Example 1:** 

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

```

 **Example 2:** 

```
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s[i] is either 'A', 'C', 'G', or 'T'.

## Solution

**Language:** C++  
**Runtime:** 1549 ms (beats 5.02%)  
**Memory:** 451.2 MB (beats 6.63%)  
**Submitted:** 2026-09-04T05:01:10.679Z  

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> S;
        unordered_map<string,int>mp;
        int k = 10;
        int n = s.length();
        string str;
        for(int i = 0;i<k;i++){
            str.push_back(s[i]);
         
        }
        //    cout << str << " ";
        mp[str] = 1;
        for(int i = k;i<n;i++){
            str.push_back(s[i]);
            str.erase(0,1);
            if(mp.find(str) == mp.end()){
                mp[str] = 1;
            }
            else{
                mp[str]++;
            }
        }
        for(auto i = mp.begin();i != mp.end();i++){
              if(i->second > 1){
                S.push_back(i->first);
              }
        }
        return S;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/repeated-dna-sequences/)