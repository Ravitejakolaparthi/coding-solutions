class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int right = 0;
        int left = 0;
        int k = s1.length();
        if (s1.length() > s2.length()) return false;
        map<char,int>window;
        map<char,int>mp;
        for (int i = 0; i < k; i++) {
            window[s2[i]]++;
            mp[s1[i]]++;
            right = i;
        }
        while (right < s2.length()) {
            int count = 0;
            for (char i : s1) {
                if (window.find(i) == window.end()) {
                    window[s2[left]]--;
                    if(window[s2[left]] == 0)
                    window.erase(s2[left]);
                    left++;
                    right++;
                    window[s2[right]]++;
                    break;
                } else {
                    count++;
                }
            }
            if (count == k){
                int flag = 0;
                for(char ch : s1) {
                if (window[ch] != mp[ch])
                {
                    flag = 1;
                    break;
                }
                }

                if (flag == 0) return true;
                    window[s2[left]]--;
                    if(window[s2[left]] == 0)
                    window.erase(s2[left]);
                    left++;
                    right++;
                    window[s2[right]]++;

		     }
        }
        return false;

    }
};