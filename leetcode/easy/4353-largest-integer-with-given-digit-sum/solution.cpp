class Solution {
public:
    vector<int>v = {0,10,100,1000,10000,100000};
    int digitsum(int x)
    {
        int rem = 0;
        int sum = 0;
        while(x > 0)
            {
                rem = x%10;
                sum += rem;
                x/=10;
            }
        return sum;
    }
    int m = 0;
    int largestInteger(int n, int s) {
        if(s == 0)
            return 0;
        for(int i = v[n-1];i <=v[n]-1;i++)
            {
                int res = digitsum(i);
                if(res == s)
                    m = max(i,m);
                    
            }
        if(m == 0)
        return -1;
        else 
        return m;
    }
};