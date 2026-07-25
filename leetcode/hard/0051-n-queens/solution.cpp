class Solution {
public:
    vector<vector<string>>answers;
    bool isSafe(int i,int j,int n,vector<string>board)
    {
        int x = i;
        int y = j;
        // while(x<n && y>=0)
        // {
        //     if(board[x][y] == 'Q') return false;
        //     x++;
        //     y--;
        // }
        // x = i;
        // y = j;
        while(x>=0 && y < n)
        {
            if(board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        x = i;
        y = j;
        while(x >= 0 && y >=0)
        {
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        // x = i;
        // y = j;
        // while(x <n && y <n)
        // {
        //     if(board[x][y] == 'Q') return false;
        //     x++;
        //     y++;
        // }
        for(int k = 0;k<n;k++){
            if(board[k][j] == 'Q') return false;
        }
        for(int k = 0;k<n;k++){
            if(board[i][k] == 'Q') return false;
        }
        return true;
    }
    void solve(int i,vector<string>&board,int n)
    {
        
            if(i == n)
            {
                answers.push_back(board);
                return ;
            }
            // if(i == n)
            // return ;
            // if(j == n)
            // return ;
            for(int j = 0;j<n;j++)
            {
                if(isSafe(i,j,n,board))
                {
                
                    board[i][j] = 'Q';
                    solve(i+1,board,n);
                    board[i][j] = '.';
                    
                }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
            vector<string>board(n,string(n,'.'));
            int Q = 0;
            solve(0,board,n);
            return answers;
    }
};