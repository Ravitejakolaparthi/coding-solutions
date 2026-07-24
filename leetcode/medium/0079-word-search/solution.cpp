class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<char>>&board,vector<vector<int>>&vis,char ch,string word,int idx)
    {
        if(i >= 0 && i<=n-1 && j <=m-1 && j>=0)
        {
        
        
            if(vis[i][j] == 1)
            {
                return false;
            }
            if(board[i][j] != ch)
            {
                return false;
            }
            if(idx == word.size()-1)
            {
                return true;
            }
                // char c = s.front();
                // string next_s = s.substr(1); 
                vis[i][j] = 1;
                if(dfs(i+1,j,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i,j+1,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i-1,j,n,m,board,vis,word[idx+1],word,idx+1)||
                 dfs(i,j-1,n,m,board,vis,word[idx+1],word,idx+1))
                 {
                    return true;
                 }
                 vis[i][j] = 0;
                 
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool x = false;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        string s = word;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                if (board[i][j] == word[0] && x == false){
                    word = s; 
                    x = dfs(i,j,n,m,board,vis,word[0],word,0);
                    if(x == true)
                    return x;
                }
            }
        }
        return x;
    }
};