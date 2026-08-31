# Pacific Atlantic Water Flow

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There is an `m x n` rectangular island that borders both the  **Pacific Ocean**  and  **Atlantic Ocean**. The  **Pacific Ocean**  touches the island's left and top edges, and the  **Atlantic Ocean**  touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the  **height above sea level**  of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is  **less than or equal to**  the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return  *a  **2D list**  of grid coordinates* `result` *where* `result[i] = [ri, ci]` *denotes that rain water can flow from cell* `(ri, ci)` *to  **both**  the Pacific and Atlantic oceans*.

 

 **Example 1:** 

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

```

 **Example 2:** 

```
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

```

 

 **Constraints:** 

- m == heights.length
- n == heights[r].length
- 1 <= m, n <= 200
- 0 <= heights[r][c] <= 105

## Solution

**Language:** C++  
**Runtime:** 306 ms (beats 5.05%)  
**Memory:** 24.9 MB (beats 21.29%)  
**Submitted:** 2026-08-31T15:32:02.585Z  

```cpp
class Solution {
public:
    vector<int>dr ={0,0,1,-1};
    vector<int>dc ={1,-1,0,0};
    vector<vector<int>>answers;
    vector<vector<int>>pacific;
    vector<vector<int>>atlantic;
    void solvepacific(vector<vector<int>>&heights,int n,int m)
    {
        queue<pair<int,int>>q;
        for(int i = 0;i<m;i++)
        {
            pacific[0][i] = 1;
            q.push({0,i});
        }
        for(int i=0;i<n;i++)
        {
            pacific[i][0] = 1;
            q.push({i,0});
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int dx = x + dr[i];
                int dy = y + dc[i];
                if(dx <n && dx >= 0 && dy < m && dy >= 0 && pacific[dx][dy] != 1)
                {
                    // pacific[dx][dy] = 1;
                    if(heights[dx][dy] >= heights[x][y])
                    {
                    pacific[dx][dy] = 1;
                    q.push({dx,dy});
                    }
            
                }
            } 
       
        }
        //  for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         // if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
        //         // {
        //         //   answers.push_back({i,j});
        //         // }
        //         cout << pacific[i][j] << " ";
        //     }
        //     cout << endl;
        // }


    }
    void solveatla(vector<vector<int>>&heights,int n,int m)
    {
              queue<pair<int,int>>q;
        for(int i = 0;i<m;i++)
        {
            atlantic[n-1][i] = 1;
            q.push({n-1,i});
        }
        for(int i=0;i<n;i++)
        {
            atlantic[i][m-1] = 1;
            q.push({i,m-1});
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int dx = x + dr[i];
                int dy = y + dc[i];
                if(dx <n && dx >= 0 && dy < m && dy >= 0 && atlantic[dx][dy] != 1)
                {
                    // atlantic[dx][dy] = 1;
                    if(heights[dx][dy] >= heights[x][y])
                    {  
                        atlantic[dx][dy] = 1;
                        q.push({dx,dy});
                    }
                   
                }
            } 
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
                // {
                //   answers.push_back({i,j});
                // }
                cout << atlantic[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n =heights.size();
        int m =heights[0].size();
        // for(int i = 0;i<n;i++)
        pacific = vector<vector<int>>(n,vector<int>(m,0));
        atlantic = vector<vector<int>>(n,vector<int>(m,0));
        solvepacific(heights,n,m);
        solveatla(heights,n,m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
                {
                    answers.push_back({i,j});
                }
            }
        }
        // set<vector<int>>s(answers.begin(),answers.end());
        // if(n == 2 && m == 2)
        // {
        //     s.insert({0,0});
        //     s.insert({n-1,m-1});
        // }
        // s.insert({0,n-1});
        // s.insert({m-1,0});
        // vector<vector<int>>result(s.begin(),s.end());
        return answers;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/pacific-atlantic-water-flow/)