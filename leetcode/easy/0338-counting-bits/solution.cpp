class Solution {
public:
    int countbits(int i)
    {
        int c = 0;
        while(i > 0)
        {
            if(i&1 == 1)
            {
            c++;
            }
            i>>=1;
        }
        return c;
    } 
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        for(int i = 1;i<n+1;i++)
        {
            v.push_back(countbits(i));
        }
        return v;
    }
};