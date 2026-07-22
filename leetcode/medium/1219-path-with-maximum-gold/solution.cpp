class Solution {
public:
    int x =0;
    // vector<int>dx = {0,0,1,-1};
    // vector<int>dy = {1,-1,0,0};
    int dfs(vector<vector<int>>&grid,vector<vector<bool>>vis,int i,int j,int n,int m,int &cnt)
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
                cout << cnt << endl;
                cout << i << " " << j << endl;
                vis[i][j] = true;
                
                    x = dfs(grid,vis,i+1,j,n,m,cnt);
                    x = dfs(grid,vis,i,j+1,n,m,cnt);
                    x = dfs(grid,vis,i-1,j,n,m,cnt);
                    x = dfs(grid,vis,i,j+1,n,m,cnt);
                    x = max(cnt,x);
                    // cout << x <<"\n";

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
                   x = max(x,dfs(grid,vis,i,j,n,m,cnt));
                }
            }
        }
        return cnt;
    }
};