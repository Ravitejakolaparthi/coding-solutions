# Shortest Path in Binary Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `n x n` binary matrix `grid`, return  *the length of the shortest  **clear path**  in the matrix*. If there is no clear path, return `-1`.

A  **clear path**  in a binary matrix is a path from the  **top-left**  cell (i.e., `(0, 0)`) to the  **bottom-right**  cell (i.e., `(n - 1, n - 1)`) such that:

- All the visited cells of the path are 0.
- All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The  **length of a clear path**  is the number of visited cells of this path.

 

 **Example 1:** 

```
Input: grid = [[0,1],[1,0]]
Output: 2

```

 **Example 2:** 

```
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

```

 **Example 3:** 

```
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

```

 

 **Constraints:** 

- n == grid.length
- n == grid[i].length
- 1 <= n <= 100
- grid[i][j] is 0 or 1

## Solution

**Language:** C++  
**Runtime:** 13 ms (beats 76.55%)  
**Memory:** 24 MB (beats 73.36%)  
**Submitted:** 2026-08-31T15:31:45.973Z  

```cpp
class Solution {
public:
    vector<int>dr = {-1,-1,-1,0,1,1,1,0};
    vector<int>dc = {-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1)
        return -1;
        if(grid.size() == 1 && grid[0].size() ==1)
        return 1;

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        q.push({0,0});
        vis[0][0] = true;
        grid[0][0] = 1;
        int dis = -1;
        int f1 = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0;k<8;k++)
            {
                int nx = x + dr[k];
                int ny = y + dc[k];
                if(nx >=0 && nx<grid.size() && ny >=0 && ny < grid[0].size() && vis[nx][ny] != true&& grid[nx][ny] != 1)
                {

                    if(nx == grid.size()-1 && ny == grid[0].size()-1)
                    {
                        f1 = 1;
                        dis = grid[x][y]+1;
                        break;
                    }
                    vis[nx][ny] = true;
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx,ny});
                }
                if(f1 == 1)
                break;
            }
            if(f1 == 1)
            break;

        }
        return dis;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/)