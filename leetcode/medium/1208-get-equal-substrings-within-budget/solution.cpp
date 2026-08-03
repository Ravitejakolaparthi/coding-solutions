class Solution {
public:
    int diffbtwch(char A,char B)
    {
        return abs(A-B);
    }
    int equalSubstring(string s, string t, int maxCost) {

        int cost = 0;
        // int x = diffbtwch(s[0],t[0]);
        int j = 0;
        int length = 0;
        for(int i = 0;i<s.length();i++)
        {
            cost += diffbtwch(s[i],t[i]);
            while(cost>maxCost)
            {
                cost -= diffbtwch(s[j],t[j]);
                j++;
            }
            length=max(length,i-j+1);
        }
        // cout << x;
        return length;
    }
};