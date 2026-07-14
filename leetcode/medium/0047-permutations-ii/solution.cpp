class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<int>&u,vector<bool>&v)
    {
        if(u.size() == n.size())
        {
            b.push_back(u);
        }
        else
        {
            for(int i = 0;i<n.size();i++)
            {
                if(v[i] == 0)
                {
                    u.push_back(n[i]);
                    v[i] = 1;
                    solve(n,u,v);
                    v[i] = 0;
                    u.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        vector<bool>v(n,0);
        vector<int>u;
        solve(nums,u,v);
        set<vector<int>>s(b.begin(),b.end());
        vector<vector<int>>res(s.begin(),s.end());
        return res;

    }
};