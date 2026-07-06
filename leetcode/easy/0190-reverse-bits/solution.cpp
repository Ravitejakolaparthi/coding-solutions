class Solution {
public:
    int reverseBits(int n) {
        int r =0;
        int b =0;

        for(int i = 0;i<32;i++)
        {
                r <<= 1;
                b = n&1;
                r |=b;
                n >> 1;
        }
        return r;
    }
};