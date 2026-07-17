class Solution {
public:
    int digitFrequencyScore(int n) {
        int s = 0;
        int rem = 0;
        while(n > 0)
        {
            rem = n%10;
            s += rem;
            n=n/10;
        }
        return s;
    }
};