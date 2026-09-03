class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n = s.length();
        int k = 0;
        int size = 0;
        int maxsize = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) == mp.end())
            {
                                // p  w 
                mp[s[i]] = 1;
                size = mp.size();
                maxsize = max(size,maxsize);
            }
            else{
                while(mp.find(s[i]) != mp.end()){  // p w // w // 0 // w
                    mp.erase(s[k]);
                    k++;
                 
                    
                }
                mp[s[i]] = 1;
                size = mp.size();
                maxsize = max(size,maxsize);
            }
        }
        return maxsize;
      
    }
};