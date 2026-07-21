# Max Area of Island

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected  **4-directionally**  (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The  **area**  of an island is the number of cells with a value `1` in the island.

Return  *the maximum  **area**  of an island in* `grid`. If there is no island, return `0`.

 

 **Example 1:** 

```
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

```

 **Example 2:** 

```
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- grid[i][j] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 3 ms  
**Memory:** 9.6 MB  
**Submitted:** 2026-07-21T10:08:21.326Z  

```cpp
class Solution {
public:
    int dfs(vector<vector<int>>grid,int n,int m,int i,int j,vector<vector<bool>>&v,int c)
    {
        if(i >= 0 && j>= 0 && i <= n-1 && j <= m-1)
        {
            if(v[i][j] == true)
            return c;
            if(grid[i][j] == 0)
            return c;
            else
            {
                v[i][j] = true;
                c+=1;
                c = dfs(grid,n,m,i,j+1,v,c);
                c = dfs(grid,n,m,i+1,j,v,c);
                c = dfs(grid,n,m,i,j-1,v,c);
                c = dfs(grid,n,m,i-1,j,v,c);
                
            }
            
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                c = max(c,dfs(grid,n,m,i,j,visited,0));
            }
        }
        return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/max-area-of-island/)