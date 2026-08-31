class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j,int n,int m,vector<vector<bool>>&v)
    {
        if(i >=0 && i <= n-1 && j >=0 && j <= m-1)
        {
            
            if(v[i][j] != true)
            {
             if(grid[i][j] != '0')
             {
                 v[i][j] = true;
                 cout << i << j<<endl;

                dfs(grid,i,j+1,n,m,v);
                dfs(grid,i+1,j,n,m,v);
                dfs(grid,i,j-1,n,m,v);
                dfs(grid,i-1,j,n,m,v);
            }
            }
        }
     
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        vector<vector<bool>>v(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && v[i][j] == false)
                {
                    c++;
                    dfs(grid,i,j,n,m,v);
                    
                }
            }
        }     
        return c;
    }
};