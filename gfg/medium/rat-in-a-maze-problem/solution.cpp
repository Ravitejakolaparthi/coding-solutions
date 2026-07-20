class Solution {
  public:
  vector<string>v;

  
  void solve(vector<vector<bool>>&visit,vector<vector<int>>&maze,int i,int j,string s,int n,char ch)
  {
      if(i>= 0 && i <= n-1 && j>=0 && j <=n-1)
      {
          if(visit[i][j] == true)
          return ;
          if(maze[i][j] == 1 && visit[i][j] == false)
          {
              if(i!=0 || j != 0)
              s += ch;
              visit[i][j] = true;
            //   return ;y
          }
          if(i == n-1 && j == n-1)
          {
              v.push_back(s);
              visit[i][j] = false;
              return ;
          }
          
          
          if(maze[i][j] == 0)
             return ;
          else
          {
              
              solve(visit,maze,i+1,j,s,n,'D');
              solve(visit,maze,i,j+1,s,n,'R');
              solve(visit,maze,i-1,j,s,n,'U');
              solve(visit,maze,i,j-1,s,n,'L');
              visit[i][j] = false;
          }
      }
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string s ="";
        int n = maze.size();
       vector<vector<bool>> visited(n,vector<bool>(n,false));
        solve(visited,maze,0,0,s,n,'\0');
        sort(v.begin(),v.end());
        return v;
    }
};