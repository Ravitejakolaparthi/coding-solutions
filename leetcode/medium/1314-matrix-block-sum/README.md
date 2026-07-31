# Matrix Block Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a `m x n` matrix `mat` and an integer `k`, return  *a matrix*  `answer`  *where each*  `answer[i][j]`  *is the sum of all elements*  `mat[r][c]`  *for* :

- i - k <= r <= i + k,
- j - k <= c <= j + k, and
- (r, c) is a valid position in the matrix.

 

 **Example 1:** 

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

```

 **Example 2:** 

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n, k <= 100
- 1 <= mat[i][j] <= 100

## Solution

**Language:** C++  
**Runtime:** 432 ms (beats 12.98%)  
**Memory:** 13.7 MB (beats 77.68%)  
**Submitted:** 2026-07-31T06:25:16.933Z  

```cpp
class Solution {
public:
    long long int sum(int i,int j,int k,vector<vector<int>>&mat)
    {
            long long int add = 0;
            int o  = 0;
            int p = 0;
            for(o = i-k;o<=i+k;o++)
            {
                if(o<0 || o >=mat.size())
                continue;
                for(p = j-k;p<=j+k;p++)
                {
                   if(p<0 || p>=mat[0].size())
                    continue;
                    else
                    {
                        add+=mat[o][p];
                    }
                }
            }
            return add;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>answers(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                answers[i][j] = sum(i,j,k,mat);
            }
        }
        return answers;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/matrix-block-sum/)