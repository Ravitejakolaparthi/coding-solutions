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
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-07-21T16:19:15.590Z  

```cpp
class Solution {
public:
    int dfs(vector<vector<int>>&mat,int i,int j,int n,int m,int c,vector<vector<bool>>&visited)
    {
        if(i >= 0 && i <=n-1 && j >=0 && j<=m-1)
        {
            if(mat[i][j] == 0)
            {
                return c;
            }
            if(visited[i][j] == true)
            {
                return c;
            }
            else
            {
                
                visited[i][j] =true;
                c =dfs(mat,i+1,j,n,m,c++,visited);
                c =dfs(mat,i,j+1,n,m,c++,visited);
                c =dfs(mat,i-1,j,n,m,c++,visited);
                c =dfs(mat,i,j-1,n,m,c++,visited);
                visited[i][j] =false;
            }
        }
        return c;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int c = 0;
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 1 && visited[i][j] == false)
                {
                    v[i][j] = dfs(mat,i,j,n,m,c,visited);
                }
            }
        }
        return v;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/01-matrix/)