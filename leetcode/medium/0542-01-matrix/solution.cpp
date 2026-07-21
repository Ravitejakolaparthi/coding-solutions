class Solution {
public:
    int dfs(vector<vector<int>>&mat,int i,int j,int n,int m,int c,vector<vector<bool>>&visited)
    {
        if(i >= 0 && i <=n-1 && j >=0 && j<=m-1)
        {
            if(mat[i][j] == 0)
            {
                return c;
            }
            if(visited[i][j] == true)
            {
                return c;
            }
            else
            {
                
                visited[i][j] =true;
                c =dfs(mat,i+1,j,n,m,c++,visited);
                c =dfs(mat,i,j+1,n,m,c++,visited);
                c =dfs(mat,i-1,j,n,m,c++,visited);
                c =dfs(mat,i,j-1,n,m,c++,visited);
                visited[i][j] =false;
            }
        }
        return c;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int c = 0;
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 1 && visited[i][j] == false)
                {
                    v[i][j] = dfs(mat,i,j,n,m,c,visited);
                }
            }
        }
        return v;
    }
};