# Shortest Bridge

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `n x n` binary matrix `grid` where `1` represents land and `0` represents water.

An  **island**  is a 4-directionally connected group of `1`'s not connected to any other `1`'s. There are  **exactly two islands**  in `grid`.

You may change `0`'s to `1`'s to connect the two islands to form  **one island**.

Return  *the smallest number of* `0` *'s you must flip to connect the two islands*.

 

 **Example 1:** 

```
Input: grid = [[0,1],[1,0]]
Output: 1

```

 **Example 2:** 

```
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

```

 **Example 3:** 

```
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

```

 

 **Constraints:** 

- n == grid.length == grid[i].length
- 2 <= n <= 100
- grid[i][j] is either 0 or 1.
- There are exactly two islands in grid.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 91.07%)  
**Memory:** 22.3 MB (beats 87.94%)  
**Submitted:** 2026-07-26T12:21:09.545Z  

```cpp
class Solution {
public:
    queue<pair<int,int>>q;
    vector<int>dr = {0,0,1,-1};
    vector<int>dc = {1,-1,0,0};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis)
    {
        if(i <=grid.size()-1 && j < grid[0].size() && j >= 0 && i >= 0)
        {
            if(vis[i][j]==true)
            return ;
            if(grid[i][j] == 0)
            {
                vis[i][j] =true;
                grid[i][j] = 1;
                q.push({i,j});
                return ;
            }
            else
            {
                vis[i][j]=true;
                grid[i][j] = 2;
                for(int k = 0;k<4;k++){
                    dfs(i+dr[k],j+dc[k],grid,vis);
                }
                
            }
        }
    }
    int f = 0;
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    // int pi = i;
                    // int pj = j;
                    dfs(i,j,grid,vis);
                    f = 1;
                }
                if(f == 1)
                break;
            }
            if(f == 1)
            break;
            
        }
        int flips = 0;
        int f1 = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
                for(int k = 0;k<4;k++)
                {
                    int nx = x + dr[k];
                    int ny = y + dc[k];
                    if(nx <=grid.size()-1 &&ny<= grid[0].size()-1 && nx >= 0&& ny>=0  &&  vis[nx][ny]!=true){

                        if(grid[nx][ny] == 1)
                        {
                            f1 = 1;
                            flips = grid[x][y];
                            break;
                        }
                        vis[nx][ny] = true;
                        grid[nx][ny] = grid[x][y] + 1;
                        // flips = grid[x][y];
                        q.push({nx,ny});
                    }
                    
                  
                }
                if(f1 == 1)
                break;
               
        }
        return flips;
        //  return ;//
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/shortest-bridge/)