class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> S;
        unordered_map<string,int>mp;
        int k = 10;
        int n = s.length();
        string str;
        for(int i = 0;i<k;i++){
            str.push_back(s[i]);
         
        }
        //    cout << str << " ";
        mp[str] = 1;
        for(int i = k;i<n;i++){
            str.push_back(s[i]);
            str.erase(0,1);
            if(mp.find(str) == mp.end()){
                mp[str] = 1;
            }
            else{
                mp[str]++;
            }
        }
        for(auto i = mp.begin();i != mp.end();i++){
              if(i->second > 1){
                S.push_back(i->first);
              }
        }
        return S;
    }
};