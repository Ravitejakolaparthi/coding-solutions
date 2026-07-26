class Solution {
public:
    queue<pair<int,int>>q;
    vector<int>dr = {0,0,1,-1};
    vector<int>dc = {1,-1,0,0};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis)
    {
        if(i <=grid.size()-1 && j < grid[0].size() && j >= 0 && i >= 0)
        {
            if(vis[i][j]==true)
            return ;
            if(grid[i][j] == 0)
            {
                vis[i][j] =true;
                grid[i][j] = 1;
                q.push({i,j});
                return ;
            }
            else
            {
                vis[i][j]=true;
                grid[i][j] = 2;
                for(int k = 0;k<4;k++){
                    dfs(i+dr[k],j+dc[k],grid,vis);
                }
                
            }
        }
    }
    int f = 0;
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    // int pi = i;
                    // int pj = j;
                    dfs(i,j,grid,vis);
                    f = 1;
                }
                if(f == 1)
                break;
            }
            if(f == 1)
            break;
            
        }
        int flips = 0;
        int f1 = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
                for(int k = 0;k<4;k++)
                {
                    int nx = x + dr[k];
                    int ny = y + dc[k];
                    if(nx <=grid.size()-1 &&ny<= grid[0].size()-1 && nx >= 0&& ny>=0  &&  vis[nx][ny]!=true){

                        if(grid[nx][ny] == 1)
                        {
                            f1 = 1;
                            flips = grid[x][y];
                            break;
                        }
                        vis[nx][ny] = true;
                        grid[nx][ny] = grid[x][y] + 1;
                        // flips = grid[x][y];
                        q.push({nx,ny});
                    }
                    
                  
                }
                if(f1 == 1)
                break;
               
        }
        return flips;
        //  return ;//
    }
};