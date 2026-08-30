# Lexicographically Largest String After Pair Transformations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`.

For each integer `x` in `nums`, start with a string consisting of exactly `x` lowercase `'a'` characters.

You may perform the following operation any number of times (including zero):

- Choose two adjacent equal letters and replace them with the next letter in the alphabet.

For example, `"aa"` can be replaced with `"b"`, and `"bb"` can be replaced with `"c"`. The pair `"zz"` cannot be replaced.

For each `x`, determine the  **lexicographically largest**  string that can be obtained.

Return an array of strings where the `ith` string is the answer for `nums[i]`.

A string `a` is  **lexicographically larger**  than a string `b` if, at the first position where they differ, `a` contains a letter that appears later in the alphabet than the corresponding letter in `b`. If the first `min(a.length, b.length)` characters are equal, the longer string is lexicographically larger.

 

 **Example 1:** 

 **Input:**  nums = [2,5,7]

 **Output:**  ["b","ca","cba"]

 **Explanation:** 

- nums[0] = 2: "aa" → "b".
- nums[1] = 5: "aaaaa" → "baaa" → "bba" → "ca".
- nums[2] = 7: "aaaaaaa" → "baaaaa" → "bbaaa" → "bbba" → "cba".
- Therefore, ans = ["b", "ca", "cba"].

 **Example 2:** 

 **Input:**  nums = [3,9,1]

 **Output:**  ["ba","da","a"]

 **Explanation:** 

- nums[0] = 3: "aaa" → "ba".
- nums[1] = 9: "aaaaaaaaa" → "baaaaaaa" → "bbaaaaa" → "bbbaaa" → "bbbba" → "cbba" → "cca" → "da".
- nums[2] = 1: No transformation can be applied, so the result is "a".
- Therefore, ans = ["ba", "da", "a"].

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 108

## Solution

**Language:** C++  
**Runtime:** 834 ms (beats 16.67%)  
**Memory:** 422.5 MB  
**Submitted:** 2026-08-30T07:07:47.385Z  

```cpp
class Solution {
public:
    vector<char>albs = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string givestring(int n){
        vector<int>arr;
        int m = n;
        int rem = 0;
        while(n>0 && arr.size() < 25){
            rem = n%2;
            arr.push_back(rem);
            n = n/2;
        }
        int Z = m/pow(2,25);
        string ans ="";
        for(int i = 0;i<arr.size() && i < albs.size()-1;i++){
            
            if(arr[i] == 1){
                ans.push_back(albs[i]);
            }
        }
        
        while(Z>0){
            ans.push_back('z');
            Z--;
            }   
                                  
      reverse(ans.begin(),ans.end());       
        return ans;
    }
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string>v(n);
        for(int i = 0;i<n;i++){
            v[i] = givestring(nums[i]);
        }
        return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/)