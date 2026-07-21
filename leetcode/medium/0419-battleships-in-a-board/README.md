# Battleships in a Board

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` matrix `board` where each cell is a battleship `'X'` or empty `'.'`, return  *the number of the  **battleships**  on*  `board`.

 **Battleships**  can only be placed horizontally or vertically on `board`. In other words, they can only be made of the shape `1 x k` (`1` row, `k` columns) or `k x 1` (`k` rows, `1` column), where `k` can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

 **Example 1:** 

```
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

```

 **Example 2:** 

```
Input: board = [["."]]
Output: 0

```

 

 **Constraints:** 

- m == board.length
- n == board[i].length
- 1 <= m, n <= 200
- board[i][j] is either '.' or 'X'.

 

 **Follow up:**  Could you do it in one-pass, using only `O(1)` extra memory and without modifying the values `board`?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.5 MB (beats 23.55%)  
**Submitted:** 2026-07-21T10:35:40.386Z  

```cpp
class Solution {
public:
    void dfs(vector<vector<char>>&g,int i,int j,int n,int m,vector<vector<bool>>&v)
    {
        if(i >= 0 && i <=n-1 && j >= 0 && j <=m-1)
        {
            if(v[i][j] == true)
            return ;
            if(g[i][j] == '.')
            return ;
            else
            {
                v[i][j] = true;
                dfs(g,i+1,j,n,m,v);
                dfs(g,i,j+1,n,m,v);
                dfs(g,i-1,j,n,m,v);
                dfs(g,i,j-1,n,m,v);
            } 
            
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int c = 0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>v(n,vector<bool>(m,false));
        // int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j] == 'X' && v[i][j] == false)
                {
                        
                        dfs(board,i,j,n,m,v);
                        c++;
                }
            }
        }
            return c;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/battleships-in-a-board/)