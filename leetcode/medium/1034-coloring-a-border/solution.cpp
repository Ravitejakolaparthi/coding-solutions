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