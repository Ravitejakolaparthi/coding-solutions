class Solution {
public:
    string removeDuplicates(string s) {
        // string s;
        string ans;
        stack<char>st;
        st.push(s[0]);
        for(int i = 1;i<s.length();i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
            while(!st.empty()){
                char x = st.top();
                ans += x;
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        
    }
};