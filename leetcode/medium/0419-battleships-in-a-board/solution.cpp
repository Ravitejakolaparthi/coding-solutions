class Solution {
public:
    void dfs(vector<vector<char>>&g,int i,int j,int n,int m,vector<vector<bool>>&v)
    {
        if(i >= 0 && i <=n-1 && j >= 0 && j <=m-1)
        {
            if(v[i][j] == true)
            return ;
            if(g[i][j] == '.')
            return ;
            else
            {
                v[i][j] = true;
                dfs(g,i+1,j,n,m,v);
                dfs(g,i,j+1,n,m,v);
                dfs(g,i-1,j,n,m,v);
                dfs(g,i,j-1,n,m,v);
            } 
            
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int c = 0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>v(n,vector<bool>(m,false));
        // int c = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j] == 'X' && v[i][j] == false)
                {
                        
                        dfs(board,i,j,n,m,v);
                        c++;
                }
            }
        }
            return c;
    }
};