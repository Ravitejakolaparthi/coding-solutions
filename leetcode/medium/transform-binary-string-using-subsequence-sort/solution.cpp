class Solution {
public:
    vector<bool> v;
    vector<bool> transformStr(string s, vector<string>& strs) {
        int ones = 0;
        int zeros = 0;
        // int qmarks = 0;
        for(int i = 0;i<s.length();i++)
            {
                if(s[i] == '1')
                    ones++;
                if(s[i] == '0')
                    zeros++;
            }
      
        for(int  i =0;i<strs.size();i++)
            {
                  int strones = 0;
                  int strzeros = 0;
                for(int j = 0;j<strs[i].length();j++)
                    {
                        if(strs[i][j] == '1')
                           strones++;
                        if(strs[i][j] == '0')
                           strzeros++;
                    }
                if(strones <= ones && strzeros <= zeros)
                    v.push_back(1);
                else
                    v.push_back(0);
            }


        return v;
    }

    
};