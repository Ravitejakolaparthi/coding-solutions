class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>distance(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    distance[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<int>directionX = {0,0,1,-1};
        vector<int>directionY = {1,-1,0,0};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int X = x+directionX[i];
                int Y = y+directionY[i];

                if(X <= n-1 && X>=0 && Y<=m-1 && Y>=0 && distance[X][Y] == -1)
                {
                    distance[X][Y] = distance[x][y] + 1;
                    q.push({X,Y});
                }
            }

        }  
        return distance;
    }
};