class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int j = c-1;
        while(i < j)
        {
            if(i*i + j*j == c)
            return true;
            else if(i*i + j*j > c)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};