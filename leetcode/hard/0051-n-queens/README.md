# N-Queens

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The  **n-queens**  puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return  *all distinct solutions to the  **n-queens puzzle***. You may return the answer in  **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

 

 **Example 1:** 

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

```

 **Example 2:** 

```
Input: n = 1
Output: [["Q"]]

```

 

 **Constraints:** 

- 1 <= n <= 9

## Solution

**Language:** C++  
**Runtime:** 46 ms (beats 5.71%)  
**Memory:** 50.2 MB (beats 5.00%)  
**Submitted:** 2026-08-31T15:47:17.132Z  

```cpp
class Solution {
public:
    vector<vector<string>>answers;
    bool isSafe(int i,int j,int n,vector<string>board)
    {
        int x = i;
        int y = j;
        // while(x<n && y>=0)
        // {
        //     if(board[x][y] == 'Q') return false;
        //     x++;
        //     y--;
        // }
        // x = i;
        // y = j;
        while(x>=0 && y < n)
        {
            if(board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        x = i;
        y = j;
        while(x >= 0 && y >=0)
        {
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        // x = i;
        // y = j;
        // while(x <n && y <n)
        // {
        //     if(board[x][y] == 'Q') return false;
        //     x++;
        //     y++;
        // }
        for(int k = 0;k<n;k++){
            if(board[k][j] == 'Q') return false;
        }
        for(int k = 0;k<n;k++){
            if(board[i][k] == 'Q') return false;
        }
        return true;
    }
    void solve(int i,vector<string>&board,int n)
    {
        
            if(i == n)
            {
                answers.push_back(board);
                return ;
            }
            // if(i == n)
            // return ;
            // if(j == n)
            // return ;
            for(int j = 0;j<n;j++)
            {
                if(isSafe(i,j,n,board))
                {
                
                    board[i][j] = 'Q';
                    solve(i+1,board,n);
                    board[i][j] = '.';
                    
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
            vector<string>board(n,string(n,'.'));
            int Q = 0;
            solve(0,board,n);
            return answers;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/n-queens/)