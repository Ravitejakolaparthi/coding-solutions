# Reverse String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with `O(1)` extra memory.

 

 **Example 1:** 

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

```

 **Example 2:** 

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s[i] is a printable ascii character.

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17.8 MB (beats 75.75%)  
**Submitted:** 2026-08-31T15:41:14.493Z  

```c
void reverseString(char* s, int sSize) {
    
    int i;
    for(int i=0;i<sSize;i++)
    {
        char temp;
         temp =   s[sSize-1];
         s[sSize-1] =  s[i];
         s[i] =  temp;
        sSize--;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-string/)