class Solution {
public:
    vector<vector<int>>b;
    void solve(vector<int>&n,vector<bool>&v,vector<int>&t)
    {
        if(t.size() == n.size())
        {
            b.push_back(t);
            return ;
        }
        else
        {
            for(int i = 0;i<n.size();i++)
            {
                if(v[i] == 0)
                {
                    t.push_back(n[i]);
                    v[i] = 1;
                    solve(n,v,t);
                    v[i] = 0;
                    t.pop_back();
                    // solve(n,v,t);
                } 
                    
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
       vector<int>t;
       vector<bool>visted(n,0);
       solve(nums,visted,t);
       return b;

    }
};