class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    // grid[i][j] = ;
                   q.push({i,j});
                }
            }
        }
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        int cnt = 0;
        while(!q.empty())
        {
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X <= n-1 && X>= 0 && Y >= 0 && Y <= m-1 && grid[X][Y] == 0)
                {
                        grid[X][Y] = grid[x][y]+1 ;
                        cnt = max(cnt,grid[X][Y]);
                        q.push({X,Y});
                }
            }
        }
        return cnt-1;
    }
};