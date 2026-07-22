# Path with Maximum Gold

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

In a gold mine `grid` of size `m x n`, each cell in this mine has an integer representing the amount of gold in that cell, `0` if it is empty.

Return the maximum amount of gold you can collect under the conditions:

- Every time you are located in a cell you will collect all the gold in that cell.
- From your position, you can walk one step to the left, right, up, or down.
- You can't visit the same cell more than once.
- Never visit a cell with 0 gold.
- You can start and stop collecting gold from any position in the grid that has some gold.

 

 **Example 1:** 

```
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

```

 **Example 2:** 

```
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 15
- 0 <= grid[i][j] <= 100
- There are at most 25 cells containing gold.

## Solution

**Language:** C++  
**Runtime:** 175 ms (beats 33.03%)  
**Memory:** 54.4 MB (beats 5.01%)  
**Submitted:** 2026-07-22T16:53:55.024Z  

```cpp
class Solution {
public:
    int x =0;
    // vector<int>dx = {0,0,1,-1};
    // vector<int>dy = {1,-1,0,0};1
    vector<int>z;
    int dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int n,int m,int &cnt)
    {
        if(i>=0 && i<=n-1 && j <= m-1 && j >= 0)
        {
            //  int x = 0;
            if(vis[i][j] == true)
            return cnt;
            if(grid[i][j] == 0)
            return cnt;
            else
            {
                cnt+=grid[i][j];
                // cout << cnt << endl;
                // cout << i << " " << j << endl;
                vis[i][j] = true;
                
                     dfs(grid,vis,i+1,j,n,m,cnt);
                     dfs(grid,vis,i,j+1,n,m,cnt);
                     dfs(grid,vis,i-1,j,n,m,cnt);
                     dfs(grid,vis,i,j-1,n,m,cnt);
                     z.push_back(cnt);
                     vis[i][j] = false;
                     cnt -= grid[i][j];
            }
           
        }
        return x;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] != 0)
                {
                   dfs(grid,vis,i,j,n,m,cnt);
                }
            }
        }
        // for(auto x : z) cout << x << " ";
        int ms = 0;
        if(!z.empty())
        ms  = *max_element(z.begin(),z.end());
        return ms;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/path-with-maximum-gold/)