# Word Search

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` grid of characters `board` and a string `word`, return `true`  *if*  `word`  *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

 **Example 1:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

```

 **Example 2:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

```

 **Example 3:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

```

 

 **Constraints:** 

- m == board.length
- n = board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consists of only lowercase and uppercase English letters.

 

 **Follow up:**  Could you use search pruning to make your solution faster with a larger `board`?

## Solution

**Language:** C++  
**Runtime:** 911 ms (beats 8.06%)  
**Memory:** 11.9 MB (beats 12.95%)  
**Submitted:** 2026-07-24T15:47:19.837Z  

```cpp
class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<char>>&board,vector<vector<int>>&vis,char ch,string word,int idx)
    {
        if(i >= 0 && i<=n-1 && j <=m-1 && j>=0)
        {
        
        
            if(vis[i][j] == 1)
            {
                return false;
            }
            if(board[i][j] != ch)
            {
                return false;
            }
            if(idx == word.size()-1)
            {
                return true;
            }
                // char c = s.front();
                // string next_s = s.substr(1); 
                vis[i][j] = 1;
                if(dfs(i+1,j,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i,j+1,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i-1,j,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i,j-1,n,m,board,vis,word[idx+1],word,idx+1))
                 {
                    return true;
                 }
                 vis[i][j] = 0;
                 
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool x = false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        string s = word;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                if (board[i][j] == word[0] && x == false){
                    word = s; 
                    x = dfs(i,j,n,m,board,vis,word[0],word,0);
                    if(x == true)
                    return x;
                }
            }
        }
        return x;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/word-search/)