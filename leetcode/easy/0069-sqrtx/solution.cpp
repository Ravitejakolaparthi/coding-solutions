class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
        return x;
        int l = 1;
        int h = x/2;
        int ans =0;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(mid == x/mid){
                return mid;
            }
            else if(mid > x/mid){
                h = mid-1;
            }
            if(mid < x/mid){
                  ans = mid;
                l = mid+1;
              
            }
        }
        return ans;
    }
};