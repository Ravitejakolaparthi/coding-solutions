class Solution {
public:
    int countRotations(string s, int k) {
        int count = 0;
        int score = 0;
        int n = s.length();
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1])
            score++;
            
        }
        if(score == k)
            count++;
        score = 0;
        for(int i = 0;i<n-1;i++){
            score = 0;
            char ch = s[0];
            s.erase(0,1);
            s.push_back(ch);
            for(int i = 0;i<n-1;i++){
                 if(s[i]==s[i+1])
                 score++;
            }
            if(score == k)
            count++;
        }
        return count;
    }
};