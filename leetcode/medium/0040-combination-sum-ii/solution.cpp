class Solution {
public:
    vector<vector<int>>b;
    void move(vector<int>&n,int s,vector<int>v,int i)
    {
        if(s >= 0 && i < n.size())
        {
            if(s == 0)
            {
                
                b.push_back(v);
            }
            else
            {
                move(n,s,v,i+1);
                v.push_back(n[i]);
                move(n,s-n[i],v,i+1);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     vector<int>v;
     sort(candidates.begin(),candidates.end());
     move(candidates,target,v,0);
     set<vector<int>>s(b.begin(),b.end());
     vector<vector<int>>res(s.begin(),s.end());
     return res;

    }
};