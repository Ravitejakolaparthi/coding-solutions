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
            else if(i->second == 1 && one ==0)
            {
                one++;
                odd++;
            }
            else
            {
               cnt++;
               odd+=i->second;
            }
        }

        if(odd > 0)
        {
            return sum + odd-cnt;
        }
        else
        {
            return sum;
        }
        





















    }
};