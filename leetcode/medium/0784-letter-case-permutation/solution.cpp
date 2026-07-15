class Solution {
public:
    vector<string>a;
    void solve(string v,int i)
    {
        if(i == v.size())
        {
            a.push_back(v);
        }
        else
        {
            if(isalpha(v[i]))
            {
                v[i] = tolower(v[i]);
                solve(v,i+1);

                v[i] = toupper(v[i]);
            }
            
            solve(v,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
            solve(s,0);
            return a;
    }
};