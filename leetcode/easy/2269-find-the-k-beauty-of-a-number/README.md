# Find the K-Beauty of a Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

The  **k-beauty**  of an integer `num` is defined as the number of  **substrings**  of `num` when it is read as a string that meet the following conditions:

- It has a length of k.
- It is a divisor of num.

Given integers `num` and `k`, return  *the k-beauty of* `num`.

Note:

- Leading zeros are allowed.
- 0 is not a divisor of any value.

A  **substring**  is a contiguous sequence of characters in a string.

 

 **Example 1:** 

```
Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.

```

 **Example 2:** 

```
Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.

```

 

 **Constraints:** 

- 1 <= num <= 109
- 1 <= k <= num.length (taking num as a string)

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8 MB (beats 75.76%)  
**Submitted:** 2026-08-01T16:08:40.723Z  

```cpp
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // cout << (to_string(num));
        int cnt = 0;
        string s = to_string(num);
        string sub = "";
        for(int i=0;i<=s.size()-k;i++)
        {
            sub = s.substr(i,k);
            if(stoi(sub) != 0 && num%(stoi(sub))==0) cnt++;
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-k-beauty-of-a-number/)