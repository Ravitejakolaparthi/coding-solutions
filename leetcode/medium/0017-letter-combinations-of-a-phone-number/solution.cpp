class Solution {
public:
    map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tvu"},{'9',"wxyz"}};
    vector<string>v;
    void solve(int i,string digits,string str)
    {
        // cout << 1;
        
            // cout << 1;
            if(i==digits.size())
            {
              v.push_back(str);
              return ;   
            }
            else
            {
                   
                string t = mp[digits[i]];
                // cout << t;
                for(int j = 0;j<t.size();j++)
                {
                    str.push_back(t[j]);
                    // cout << str <<endl;
                    solve(i+1,digits,str);
                    str.pop_back();
                }
            }
        
    }
    vector<string> letterCombinations(string digits) {
        string str;
        solve(0,digits,str);
        return v;
    }
};