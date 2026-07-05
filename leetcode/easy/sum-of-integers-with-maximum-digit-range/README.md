# Q1. Sum of Integers with Maximum Digit Range

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums`.

The  **digit range**  of an integer is defined as the difference between its  **largest**  digit and  **smallest**  digit.

For example, the digit range of 5724 is `7 - 2 = 5`.

Return the sum of all integers in `nums` whose  **digit range**  is equal to the  **maximum digit range**  among all integers in the array.

 

 **Example 1:** 

 **Input:**  nums = [5724,111,350]

 **Output:**  6074

 **Explanation:** 

`i`	`nums[i]`	Largest	Smallest	Digit Range
0	5724	7	2	5
1	111	1	1	0
2	350	5	0	5

The maximum digit range is 5. The integers with this digit range are 5724 and 350, so the answer is `5724 + 350 = 6074`.

 **Example 2:** 

 **Input:**  nums = [90,900]

 **Output:**  990

 **Explanation:** 

`i`	`nums[i]`	Largest	Smallest	Digit Range
0	90	9	0	9
1	900	9	0	9

The maximum digit range is 9. Both integers have this digit range, so the answer is `90 + 900 = 990`.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 10 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.1 MB  
**Submitted:** 2026-07-05T02:41:05.856Z  

```cpp
class Solution {
public:
    int rangeof(int n)
    {
        vector<int>v;
         int s = 999999;
         int l = -1;
         int rem = 0;
         while(n>0)
             {
                rem = n%10;
                s = min(s,rem);
                 // cout << s <<endl;
                l = max(l,rem);
                 // cout << l <<endl;
                n = n/10; 
             }
        int r = l-s;
        return r;
       
    }
    
    int maxDigitRange(vector<int>& nums) {
        vector<int>v(nums.size());
        for(int i = 0;i<nums.size();i++)
            {
                v[i] = rangeof(nums[i]);  
            }
            for(int i = 0;i<v.size();i++)
                cout << v[i];
        return 1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/)