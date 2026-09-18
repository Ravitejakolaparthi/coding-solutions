class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int i = 0;
        int n  = nums.size();
        int j = 0;
        int ans = 9999999;
        for(int l = 0;l<n;l++){
            sum+=nums[l];
        }
        if(sum<target) return 0;
        sum = 0;
        while(j < n){
            sum += nums[j];
                j++;
               while (sum >= target) {
                    ans = min(ans, j - i);
                    sum -= nums[i];
                    i++;
                }
                
            }
        
        return ans;

    }
};