class Solution {
public:
    vector<vector<int>>b;
    void move(vector<int>&u,int s,vector<int>v,int i)
    {
        if(s >= 0 && i <u.size())
        {
        if(s == 0)
        {
            b.push_back(v);
        }
        else{
            move(u,s,v,i+1);
            v.push_back(u[i]);
            move(u,s-u[i],v,i); 
        //    v.push_back(u[i]);
         
        }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
            vector<int>v;
            move(candidates,target,v,0);
            return b;
        
    }
};