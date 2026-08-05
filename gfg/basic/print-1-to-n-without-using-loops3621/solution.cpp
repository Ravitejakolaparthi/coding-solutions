class Solution {
  public:
  void solve(int n,int c)
  {
      if(c == n+1)
      return ;
      else{
          cout << c << " ";
          solve(n,c+1);
      }
  }
    void printTillN(int n) {
         solve(n,1);
        // return 0;
    }
};