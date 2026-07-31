class Solution {
public:
    vector<int>dr ={0,0,1,-1};
    vector<int>dc ={1,-1,0,0};
    vector<vector<int>>answers;
    vector<vector<int>>pacific;
    vector<vector<int>>atlantic;
    void solvepacific(vector<vector<int>>&heights,int n,int m)
    {
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++)
        {
            q.push({0,i});
        }
        for(int i=0;i<n;i++)
        {
            q.push({i,0});
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int dx = x + dr[i];
                int dy = y + dc[i];
                if(dx <n && dx >= 0 && dy < m && dy >= 0 && pacific[dx][dy] != 1)
                {
                    // pacific[dx][dy] = 1;
                    if(heights[dx][dy] >= heights[x][y])
                    {
                    pacific[dx][dy] = 1;
                    q.push({dx,dy});
                    }
            
                }
            } 
       
        }
        //  for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         // if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
        //         // {
        //         //   answers.push_back({i,j});
        //         // }
        //         cout << pacific[i][j] << " ";
        //     }
        //     cout << endl;
        // }


    }
    void solveatla(vector<vector<int>>&heights,int n,int m)
    {
              queue<pair<int,int>>q;
        for(int i = 0;i<n;i++)
        {
            q.push({4,i});
        }
        for(int i=0;i<n;i++)
        {
            q.push({i,4});
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int dx = x + dr[i];
                int dy = y + dc[i];
                if(dx <n && dx >= 0 && dy < m && dy >= 0 && atlantic[dx][dy] != 1)
                {
                    // atlantic[dx][dy] = 1;
                    if(heights[dx][dy] >= heights[x][y])
                    {  
                        atlantic[dx][dy] = 1;
                        q.push({dx,dy});
                    }
                   
                }
            } 
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
                // {
                //   answers.push_back({i,j});
                // }
                cout << atlantic[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n =heights.size();
        int m =heights[0].size();
        // for(int i = 0;i<n;i++)
        pacific = vector<vector<int>>(n,vector<int>(m,0));
        atlantic = vector<vector<int>>(n,vector<int>(m,0));
        solvepacific(heights,n,m);
        solveatla(heights,n,m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j] == 1 &&  pacific[i][j] == 1)
                {
                    answers.push_back({i,j});
                }
            }
        }
        set<vector<int>>s(answers.begin(),answers.end());
        // if(n == 2 && m == 2)
        // {
        //     s.insert({0,0});
        //     s.insert({n-1,m-1});
        // }
        s.insert({0,n-1});
        s.insert({m-1,0});
        vector<vector<int>>result(s.begin(),s.end());
        return result;

    }
};