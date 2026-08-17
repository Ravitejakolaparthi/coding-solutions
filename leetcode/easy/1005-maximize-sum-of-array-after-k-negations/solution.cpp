class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // int thing = 0;
         int j = 0;
         int sum=0;
        sort(nums.begin(),nums.end());
        while( j < nums.size() && nums[j] < 0 && k > 0){
                k--;
                nums[j] = -1 * nums[j];
                j++;
            }
            if(k > 0){
                    sort(nums.begin(),nums.end());
                    if(nums.front() >= 0){
                        if(k%2 == 0)
                        nums[0] = nums[0];
                        else
                        nums[0] = -1 * nums[0];
                    }
            }
            for(int i = 0;i<nums.size();i++){
                sum += nums[i];
            }
        
        return sum;
    }
};