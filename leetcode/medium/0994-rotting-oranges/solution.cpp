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