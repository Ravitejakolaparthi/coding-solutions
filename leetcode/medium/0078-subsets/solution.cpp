class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>v,int i)
    {
        if(i == n.size())
        {
            b.push_back(v);
           
        }
        else
        {
           
            solve(n,v,i+1);
            v.push_back(n[i]);
            solve(n,v,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(nums,v,0);
        return b;
        
    }
};