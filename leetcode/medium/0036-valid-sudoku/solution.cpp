class Solution {
public:
    int n,m;
    int find(int i){
        if(i < 3) return 0;
        if(i >= 3 && i < 6) return 3;
        if(i >= 6) return 6;
        return -1;
    } 
    bool checkrow(int i,vector<vector<char>>&b){
        set<char>s;
        for(int k = 0;k<n;k++){
            if(b[i][k] == '.') continue;
            if(s.count(b[i][k]) > 0)
            return false;
            else{
                s.insert(b[i][k]);
            }
        }
        return true;
    }
    bool checkcol(int j,vector<vector<char>>&b){
        set<char>s;
        for(int k=0;k<m;k++){
            if(b[k][j] == '.') continue;
            if(s.count(b[k][j]) > 0)
            return false;
            else
            s.insert(b[k][j]);
        }
        return true;
    }
    bool checkBox(int i,int j,vector<vector<char>>&b){
        set<char>s;
        int row = find(i);
        int col = find(j);
        for(int k = row;k<row+3;k++){
            for(int l = col;l<col+3;l++)
            {
                if(b[k][l] == '.') continue;
                if(s.count(b[k][l]) > 0) 
                return false;
                else
                s.insert(b[k][l]);
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>&b){
        if(checkrow(i,b) && checkcol(j,b) && checkBox(i,j,b))
        return true;
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         n = board.size();
         m = board[0].size();
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    if(board[i][j] != '.'){
                        if(!solve(i,j,board))
                        return false;
                    }
                }
            }
       return true;
    }
};