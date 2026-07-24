# Rotting Oranges

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` `grid` where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is  **4-directionally adjacent**  to a rotten orange becomes rotten.

Return  *the minimum number of minutes that must elapse until no cell has a fresh orange*. If  *this is impossible, return*  `-1`.

 

 **Example 1:** 

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

```

 **Example 2:** 

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

```

 **Example 3:** 

```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- grid[i][j] is 0, 1, or 2.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17 MB (beats 39.88%)  
**Submitted:** 2026-07-24T03:17:31.436Z  

```cpp
class Solution {
public:
    vector<int>dr = {0,0,1,-1};
    vector<int>dc = {1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int b = 0,c = 0;
         for(int i= 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                b++;
                if(grid[i][j] == 1)
                c++;
            }
        }
        
        if(c == n*m)
        return -1;
        if(c == 0)
        return 0;
        if(b ==0)
        return -1;
        queue<pair<int,int>> q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        } 
        int minutes = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx >= 0 && nx <= n-1 && ny <= m-1 && ny >= 0 && vis[nx][ny] == false && grid[nx][ny]==1)
                {
                    vis[nx][ny] = true;
                    grid[nx][ny] = grid[x][y] + 1;
                    // minutes++;
                    q.push({nx,ny});
                }
            }


        }
        int maki = 0;
        int z = 0;
        for(int i= 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    z++;
                if(grid[i][j] >= maki)
                {
                    maki=grid[i][j];
                    
                }
            }
        }
        if(z == 0)
        return maki-2;
        else
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rotting-oranges/)