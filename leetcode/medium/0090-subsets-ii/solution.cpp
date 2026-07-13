class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>v,int i)
    {
        if(i == n.size())
        {
            sort(v.begin(),v.end());
            b.push_back(v);
        }
        else
        {
            solve(n,v,i+1);
            v.push_back(n[i]);
            solve(n,v,i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>u;
       solve(nums,u,0);
       set<vector<int>>s(b.begin(),b.end());
       vector<vector<int>>v(s.begin(),s.end()); 
       return v;
    }
};