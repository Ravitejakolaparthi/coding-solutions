class Solution {
public:
    int mySqrt(int x) {
        if(x <= 2)
        return x;
        int l = 0;
        int h = x/2;
        int ans =0;
        while(l<=h)
        {
            ans = l+(h-l)/2;
            if(ans == x/ans){
                return ans;
            }
            if(ans > x/ans){
                h = ans-1;
            }
            if(ans < x/ans){
                l = ans+1;
            }
        }
        return ans-1;
    }
};