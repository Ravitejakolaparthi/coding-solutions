class Solution {
public:
    bool check(int limit,int threshold,vector<int>&nums){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += (nums[i] + limit-1)/limit;
            if(sum > threshold){
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid,threshold,nums)){
                high = mid-1; 
            }
            else{
                
                 low = mid+1;
            }
        }
        return low;

    }
};