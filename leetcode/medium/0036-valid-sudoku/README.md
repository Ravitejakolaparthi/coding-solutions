# Valid Sudoku

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated  **according to the following rules** :

- Each row must contain the digits 1-9 without repetition.
- Each column must contain the digits 1-9 without repetition.
- Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

 **Note:** 

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

 

 **Example 1:** 

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

```

 **Example 2:** 

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

```

 

 **Constraints:** 

- board.length == 9
- board[i].length == 9
- board[i][j] is a digit 1-9 or '.'.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 35.01%)  
**Memory:** 26.7 MB (beats 5.63%)  
**Submitted:** 2026-07-16T08:47:43.525Z  

```cpp
class Solution {
public:
    bool checkrow(vector<vector<char>>&b,int i,int j){
        unordered_set<char>s;
             for(j = 0;j<9;j++)
            {
                if(b[i][j] == '.') continue;
                if(s.find(b[i][j]) == s.end())
                {
                    s.insert(b[i][j]);
                }
                else{
                    return false;
                }
            }
            return true;
    }
    bool find(vector<vector<char>>&b,int i,int j)
    {
        unordered_set<int>s;
        for(int k = i;k<i+3;k++)
        {
            for(int l = j;l<j+3;l++)
            {
                if(b[k][l] == '.') continue;
                if(s.find(b[k][l]) == s.end())
                {
                    s.insert(b[k][l]);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;

    }
    bool checkbox(vector<vector<char>>&b,int i,int j) {
           
           int row = (i/3)*3;
           int col = (j/3)*3;
           return  find(b,row,col);
           
            
    }
    bool checkcol(vector<vector<char>>&b,int i,int j){
            unordered_set<char>s;
             for(i = 0;i<9;i++)
            {
                if(b[i][j] == '.') continue;
                if(s.find(b[i][j]) == s.end())
                {
                    s.insert(b[i][j]);
                }
                else{
                    return false;
                }
            }
            return true;
    }
    bool solve(vector<vector<char>>&b,int i,int j)
        {
            return checkrow(b,i,j) && checkcol(b,i,j) && checkbox(b,i,j);
        }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                   continue;
                }
                else
                {
                     if(!solve(board,i,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-sudoku/)