class Solution {
public:
    vector<string>s;
    void solve(int o,int c,int n,string curr)
    {
        if(o == n && c == n)
        {
            s.push_back(curr);
        }
        else
        {
            if(o < n)
            {
                solve(o+1,c,n,curr+"(");
            }
            if(o > c)
            {
                solve(o,c+1,n,curr+")");
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(0,0,n,curr);  
        return s;
    }
};