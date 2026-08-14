class Solution {
public:
    	bool check(int limit,int k,vector<int>&nums){
		int sum = 0;
		//k-=1;
		for(int i = 0;i<nums.size();i++){
			if(sum + nums[i] <= limit){
				sum += nums[i];
			}
			else{
				k--;
				sum = nums[i];
			}
		}
		return k <= 0;
	}
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i = 0;i<nums.size();i++) high += nums[i];
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid,k,nums)){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return low;
    }
};