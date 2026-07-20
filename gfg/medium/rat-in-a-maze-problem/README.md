# Rat in a Maze

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary matrix  **maze[][]**  of size **n × n**  containing values  **0**  and  **1**, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).

- 1 represents an open cell through which the rat can move.
- 0 represents a blocked cell that cannot be traversed.

The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

 **Note:**  Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

 **Examples:** 

```
Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

```

```
Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.

```

 **Constraints:** 
2 ≤ n ≤ 5
0 ≤ maze[i][j] ≤ 1

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-20T10:38:47.961Z  

```cpp
class Solution {
  public:
  vector<string>v;

  
  void solve(vector<vector<bool>>&visit,vector<vector<int>>&maze,int i,int j,string s,int n,char ch)
  {
      if(i>= 0 && i <= n-1 && j>=0 && j <=n-1)
      {
          if(visit[i][j] == true)
          return ;
          if(maze[i][j] == 1 && visit[i][j] == false)
          {
              if(i!=0 || j != 0)
              s += ch;
              visit[i][j] = true;
            //   return ;y
          }
          if(i == n-1 && j == n-1)
          {
              v.push_back(s);
              visit[i][j] = false;
              return ;
          }
          
          
          if(maze[i][j] == 0)
             return ;
          else
          {
              
              solve(visit,maze,i+1,j,s,n,'D');
              solve(visit,maze,i,j+1,s,n,'R');
              solve(visit,maze,i-1,j,s,n,'U');
              solve(visit,maze,i,j-1,s,n,'L');
              visit[i][j] = false;
          }
      }
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string s ="";
        int n = maze.size();
       vector<vector<bool>> visited(n,vector<bool>(n,false));
        solve(visited,maze,0,0,s,n,'\0');
        sort(v.begin(),v.end());
        return v;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)