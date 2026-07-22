# 01 Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` binary matrix `mat`, return  *the distance of the nearest* `0` *for each cell*.

The distance between two cells sharing a common edge is `1`.

 

 **Example 1:** 

```
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

```

 **Example 2:** 

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 104
- 1 <= m * n <= 104
- mat[i][j] is either 0 or 1.
- There is at least one 0 in mat.

 

 **Note:**  This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

## Solution

**Language:** C++  
**Runtime:** 5 ms (beats 95.72%)  
**Memory:** 34.7 MB (beats 77.62%)  
**Submitted:** 2026-07-22T10:04:21.540Z  

```cpp
class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>distance(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int>directionX = {0,0,1,-1};
        vector<int>directionY = {1,-1,0,0};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int X = x+directionX[i];
                int Y = y+directionY[i];

                if(X <= n-1 && X>=0 && Y<=m-1 && Y>=0 && distance[X][Y] == -1)
                {
                    distance[X][Y] = distance[x][y] + 1;
                    q.push({X,Y});
                }
            }

        }  
        return distance;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/01-matrix/)