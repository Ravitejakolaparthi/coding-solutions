class Solution {
public:
    // vector<vector<int>>answer;
    const  int MOD = 1e9+7;
    map<tuple<int,int,int>,long long>mp;
    int solve(int n,int k,int has_even)
    {
       long long  int ans = 0;
        
        if(k == 0 && n == 0 && has_even >= 1)
            return 1;
        if(k<0)
            return 0;
        if(n<0)
            return 0;
        else
        {   
                auto key = make_tuple(n,k,has_even);
                if(mp.find(key)!=mp.end())
                return mp[key];
                for(int i = 1;i<=n;i++)
                    {
                        int new_has_even = has_even;
                        if(i%2 == 0)
                        {
                            new_has_even = 1;
                        }
                        // v.push_back(i);
                        ans = (ans +solve(n-i,k-1,new_has_even))%MOD;
                        // v.pop_back();
                    }
                    mp[key] =ans;
        }
        return (int)ans;
    }
    int countValidSequences(int n, int k) {
        // vector<int>v;
        // int p = 1;
        int o = 0;
        o = solve(n,k,0);
        return o;
    }
};