class Solution {
public:
    long long sumAndMultiply(int n) {
        long long int m = 0;
        long long int v = 0;
        long long int sum = 0;
        int i = 0;
        while(n>0)
        {
            m = n%10;
            if(m>0)
            {
                v += m*pow(10,i);
                sum += m;
                i++;
            }
            n =n/10;
        }
        v = v*sum;
        return v;
    }
};