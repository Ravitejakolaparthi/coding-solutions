# Count Valid Sequences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **positive**  integers `n` and `k`.

A  **valid sequence**  is a sequence of `k` positive integers such that:

- The sum of all integers in the sequence is equal to n.
- The product of all integers in the sequence is even.

Return the number of valid sequences. Since the answer may be very large, return it  **modulo**  `109​​​​​​​ + 7`.

Two sequences are considered  **different**  if they differ at any index. For example, `[1, 1, 2]` and `[1, 2, 1]` are considered different sequences.

 

 **Example 1:** 

 **Input:**  n = 5, k = 3

 **Output:**  3

 **Explanation:** 

The sequences of length `k = 3` whose sum is 5 are:

Sequence	Product	Parity
`[1, 1, 3]`	`1  *1*  3 = 3`	Odd
`[1, 2, 2]`	`1  *2*  2 = 4`	Even
`[2, 1, 2]`	`2  *1*  2 = 4`	Even
`[2, 2, 1]`	`2  *2*  1 = 4`	Even
`[1, 3, 1]`	`1  *3*  1 = 3`	Odd
`[3, 1, 1]`	`3  *1*  1 = 3`	Odd

There are 3 sequences with an even product, thus the answer is 3.

 **Example 2:** 

 **Input:**  n = 3, k = 2

 **Output:**  2

 **Explanation:** 

The sequences of length `k = 2` whose sum is 3 are:

Sequence	Product	Parity
`[1, 2]`	`1 * 2 = 2`	Even
`[2, 1]`	`2 * 1 = 2`	Even

There are 2 sequences with an even product, thus the answer is 2.

 **Example 3:** 

 **Input:**  n = 5, k = 5

 **Output:**  0

 **Explanation:** 

The only possible sequence of length `k = 5` whose sum is 5 is `[1, 1, 1, 1, 1]`, which has an odd product. Thus, the answer is 0.

 

 **Constraints:** 

- 1 <= n <= 5 * 105
- 1 <= k <= n

## Solution

**Language:** C++  
**Runtime:** 363 ms  
**Memory:** 12.7 MB  
**Submitted:** 2026-07-28T09:34:32.517Z  

```cpp
class Solution {
public:
    // vector<vector<int>>answer;
    const  int MOD = 1e9+7;
    map<tuple<int,int,int>,long long>mp;
    int solve(int n,int k,int has_even)
    {
       long long  int ans = 0;
        
        if(k == 0 && n == 0 && has_even >= 1)
            return 1;
        if(k<0)
            return 0;
        if(n<0)
            return 0;
        else
        {   
                auto key = make_tuple(n,k,has_even);
                if(mp.find(key)!=mp.end())
                return mp[key];
                for(int i = 1;i<=n;i++)
                    {
                        int new_has_even = has_even;
                        if(i%2 == 0)
                        {
                            new_has_even = 1;
                        }
                        // v.push_back(i);
                        ans = (ans +solve(n-i,k-1,new_has_even))%MOD;
                        // v.pop_back();
                    }
                    mp[key] =ans;
        }
        return (int)ans;
    }
    int countValidSequences(int n, int k) {
        // vector<int>v;
        // int p = 1;
        int o = 0;
        o = solve(n,k,0);
        return o;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-valid-sequences/)