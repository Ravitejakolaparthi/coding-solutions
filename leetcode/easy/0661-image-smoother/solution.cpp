class Solution {
public:
    vector<int>dr = {-1,-1,-1,0,1,1,1,0};
    vector<int>dc = {-1,0,1,1,1,0,-1,-1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int cnt = 0;
                for(int k = 0;k<8;k++)
                {
                    int x = i + dr[k];
                    int y = j + dc[k];
                    if(x >= 0&& x<=n-1 && y <=m-1 && y >= 0)
                    {
                        grid[i][j] += img[x][y];
                        cnt++;
                    }
                }
                grid[i][j] += img[i][j];
                cnt++;
                grid[i][j] = floor(grid[i][j]/cnt);

            }
        } 
        return grid;
    }

};