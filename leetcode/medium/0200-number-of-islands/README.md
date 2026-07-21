# Number of Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return  *the number of islands*.

An  **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

 **Example 1:** 

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

```

 **Example 2:** 

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 28 ms (beats 49.01%)  
**Memory:** 16.7 MB (beats 65.60%)  
**Submitted:** 2026-07-21T06:29:42.989Z  

```cpp
class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m,vector<vector<bool>>&v)
    {
        if(i >=0 && i <= n-1 && j >=0 && j <= m-1)
        {
            
            if(v[i][j] == true)
            return ;
            if(grid[i][j] == '0')
            return ;
            else
            {
                v[i][j] =true;
                dfs(grid,i-1,j,n,m,v);
                dfs(grid,i,j+1,n,m,v);
                dfs(grid,i+1,j,n,m,v);
                dfs(grid,i,j-1,n,m,v);
              
            }

        }
        // return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        vector<vector<bool>>v(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && v[i][j] == false)
                {
                    c++;
                    dfs(grid,i,j,n,m,v);
                    
                }
            }
        }     
        return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-islands/)