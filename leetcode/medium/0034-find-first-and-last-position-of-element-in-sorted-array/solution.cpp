class Solution {
public:
    bool check1(int limit,int target,vector<int>&nums){
            if(nums[limit]  == target)
            return true;
            return false;
    }

    int solve1(int high,int target,vector<int>&nums){
        int low = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check1(mid,target,nums)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    int solve2(int low,int target,vector<int>&nums){
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check1(mid,target,nums)){
                low = mid + 1;
            }
            else{
                // low = mid + 1;
                high = mid - 1;
            }
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int low = 0;
        int high = nums.size()-1;
        vector<int>v = {-1,-1};
        // 5 7 7 8 8 10
        // 0 1 2 3 4 5
        while(low <= high){
            int  mid = low + (high-low)/2;
            if(nums[mid]== target){
                    v[0] = solve1(mid,target,nums);
                    v[1] = solve2(mid,target,nums);
                    return v;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return v;
    }
};