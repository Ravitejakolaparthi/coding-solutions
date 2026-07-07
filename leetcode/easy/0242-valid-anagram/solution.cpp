class Solution {
public:
    bool isAnagram(string s, string t) {
        char m = 0;
        for(int i = 0;i<s.size();i++)
        {
            m^= s[i];
            m^=t[i];
        }
        if(m == 0)
        return true;
        else 
        return false;
    }
};