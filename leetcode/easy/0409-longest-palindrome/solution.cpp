class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
        return 1;

        int sum = 0;
        int odd = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<s.size();i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = 1;
            }
            else
            {
                mp[s[i]]++;
            }
        }
        int one  = 0;
        int cnt = 0;
        for(auto i = mp.begin();i!=mp.end();i++)
        {
            if(i->second%2 == 0)
            {
            sum+=i->second;
            }
            else
            {
               cnt++;
               odd+=i->second;

            }

        }
        // cnt-=1;
        if(odd > 0)
        {
            return sum + odd-cnt+1;
        }
        else
        {
            return sum;
        }
        





















    }
};