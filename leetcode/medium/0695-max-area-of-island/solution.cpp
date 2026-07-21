class Solution {
public:
    int dfs(vector<vector<int>>grid,int n,int m,int i,int j,vector<vector<bool>>&v,int c)
    {
        if(i >= 0 && j>= 0 && i <= n-1 && j <= m-1)
        {
            if(v[i][j] == true)
            return c;
            if(grid[i][j] == 0)
            return c;
            else
            {
                v[i][j] = true;
                c+=1;
                c = dfs(grid,n,m,i,j+1,v,c);
                c = dfs(grid,n,m,i+1,j,v,c);
                c = dfs(grid,n,m,i,j-1,v,c);
                c = dfs(grid,n,m,i-1,j,v,c);
                
            }
            
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                c = max(c,dfs(grid,n,m,i,j,visited,0));
            }
        }
        return c;
    }
};