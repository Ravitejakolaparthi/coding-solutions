# Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return  *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.

 **Note**  that intervals which only touch at a point are  **non-overlapping**. For example, `[1, 2]` and `[2, 3]` are non-overlapping.

 

 **Example 1:** 

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

```

 **Example 2:** 

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

```

 **Example 3:** 

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

```

 

 **Constraints:** 

- 1 <= intervals.length <= 105
- intervals[i].length == 2
- -5  *104 <= starti < endi <= 5*  104

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-08-18T10:38:24.671Z  

```cpp

class Solution {
public:
    #define f first
    #define s second
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {               
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1];
        });
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                cout << intervals[i][j] << " ";
            }
            cout << endl;
        }
        int j = 0;
        for(int i = 1;i<n;i++){
            
            if(intervals[j][1] > intervals[i][0]){
                 cnt++;
                 
            }else{
                j = i;
            }
            
        }
        // if(n == cnt) return 1;
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/non-overlapping-intervals/)