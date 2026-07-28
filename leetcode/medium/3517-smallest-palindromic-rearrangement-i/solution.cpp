class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(int i = 0;i<s.length();i++)
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
        string s1(s.length(),' ');
        int left = 0;
        int right = s.length() - 1;
        for(auto& i : mp)
        {
            
            while(i.second >= 2) 
            {
                s1[left] = i.first;
                s1[right] = i.first;
                left++;
                right--;
                i.second -= 2; 
            }
        }

        for(auto& i : mp)
        {
            if(i.second > 0)
            {
                s1[left] = i.first; 
                i.second = 0;
                break;
            }
        }
        return s1;
    }
};