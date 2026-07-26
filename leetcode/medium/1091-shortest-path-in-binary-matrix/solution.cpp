class Solution {
public:
    vector<int>dr = {-1,-1,-1,0,1,1,1,0};
    vector<int>dc = {-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1)
        return -1;
        if(grid.size() == 1 && grid[0].size() ==1)
        return 1;

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        q.push({0,0});
        vis[0][0] = true;
        grid[0][0] = 1;
        int dis = -1;
        int f1 = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0;k<8;k++)
            {
                int nx = x + dr[k];
                int ny = y + dc[k];
                if(nx >=0 && nx<grid.size() && ny >=0 && ny < grid[0].size() && vis[nx][ny] != true&& grid[nx][ny] != 1)
                {

                    if(nx == grid.size()-1 && ny == grid[0].size()-1)
                    {
                        f1 = 1;
                        dis = grid[x][y]+1;
                        break;
                    }
                    vis[nx][ny] = true;
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx,ny});
                }
                if(f1 == 1)
                break;
            }
            if(f1 == 1)
            break;

        }
        return dis;
    }
};