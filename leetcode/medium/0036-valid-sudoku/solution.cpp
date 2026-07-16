class Solution {
public:
    bool checkrow(vector<vector<char>>&b,int i,int j){
        unordered_set<char>s;
             for(j = 0;j<9;j++)
            {
                if(b[i][j] == '.') continue;
                if(s.find(b[i][j]) == s.end())
                {
                    s.insert(b[i][j]);
                }
                else{
                    return false;
                }
            }
            return true;
    }
    bool find(vector<vector<char>>&b,int i,int j)
    {
        unordered_set<int>s;
        for(int k = i;k<i+3;k++)
        {
            for(int l = j;l<j+3;l++)
            {
                if(b[k][l] == '.') continue;
                if(s.find(b[k][l]) == s.end())
                {
                    s.insert(b[k][l]);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;

    }
    bool checkbox(vector<vector<char>>&b,int i,int j) {
           
           int row = (i/3)*3;
           int col = (j/3)*3;
           return  find(b,row,col);
           
            
    }
    bool checkcol(vector<vector<char>>&b,int i,int j){
            unordered_set<char>s;
             for(i = 0;i<9;i++)
            {
                if(b[i][j] == '.') continue;
                if(s.find(b[i][j]) == s.end())
                {
                    s.insert(b[i][j]);
                }
                else{
                    return false;
                }
            }
            return true;
    }
    bool solve(vector<vector<char>>&b,int i,int j)
        {
            return checkrow(b,i,j) && checkcol(b,i,j) && checkbox(b,i,j);
        }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                   continue;
                }
                else
                {
                     if(!solve(board,i,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};