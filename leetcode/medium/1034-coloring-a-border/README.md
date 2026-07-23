# Coloring A Border

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` integer matrix `grid`, and three integers `row`, `col`, and `color`. Each value in the grid represents the color of the grid square at that location.

Two squares are called  **adjacent**  if they are next to each other in any of the 4 directions.

Two squares belong to the same  **connected component**  if they have the same color and they are adjacent.

The  **border of a connected component**  is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the  **border**  of the  **connected component**  that contains the square `grid[row][col]` with `color`.

Return  *the final grid*.

 

 **Example 1:** 

```
Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]

```

 **Example 2:** 

```
Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]

```

 **Example 3:** 

```
Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- 1 <= grid[i][j], color <= 1000
- 0 <= row < m
- 0 <= col < n

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 18.2 MB (beats 42.19%)  
**Submitted:** 2026-07-23T08:23:06.079Z  

```cpp
class Solution {
public:
    vector<int>dr={0,0,1,-1};
    vector<int>dc={1,-1,0,0};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>>dummy = grid;
        int og = grid[row][col];
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>connectedarea;
        queue<pair<int,int>>traverse;
        vis[row][col] = true;
        connectedarea.push({row,col});
        while(!connectedarea.empty())
        {
            int x = connectedarea.front().first;
            int y = connectedarea.front().second;
            traverse.push({x,y});
            connectedarea.pop();
            for(int i = 0;i<4;i++)
            {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx <= n-1 && nx >= 0 && ny >= 0 && ny <= m-1 && grid[nx][ny] == og)
                {
                    if(vis[nx][ny] == false)
                    {
                    vis[nx][ny] = true;
                    connectedarea.push({nx,ny});
                    }
                }
            }
            
        }
        while(!traverse.empty())
        {
            int x = traverse.front().first;
            int y = traverse.front().second;
            traverse.pop();
            for(int i = 0;i<4;i++)
            {
                int nx = x+dr[i];
                int ny = y+dc[i];
                if(nx  > n-1 || nx < 0 || ny > m-1 || ny < 0 ||
                grid[nx][ny] != og)
                {
                    dummy[x][y] = color;
                }
            }
        }
            return dummy;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/coloring-a-border/)