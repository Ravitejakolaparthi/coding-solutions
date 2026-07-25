class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        int c = 0;
        int r;
        while(n>0)
        {
            r = n%10;
            v.push_back(r);
            n = n/10;
            c++;
        }
        sort(v.begin(),v.end());
        return v[c-1] * v[c-2];
        

    }
};