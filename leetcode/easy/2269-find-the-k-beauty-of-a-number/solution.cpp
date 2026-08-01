class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // cout << (to_string(num));
        int cnt = 0;
        string s = to_string(num);
        string sub = "";
        for(int i=0;i<=s.size()-k;i++)
        {
            sub = s.substr(i,k);
            if(stoi(sub) != 0 && num%(stoi(sub))==0) cnt++;
        }
        return cnt;
    }
};