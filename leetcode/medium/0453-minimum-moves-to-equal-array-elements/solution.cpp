class Solution {
public:
    bool  isequal(vector<int>nums){
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1])
            return false;
        }
        return true;
    }
    int minMoves(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int count = 0;
        int m = *min_element(nums.begin(),nums.end());
        if(isequal(nums)){
            return 0;
        }
        else{
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0 && m > 0){
                count += nums[i] - m;
            }
            else if(nums[i] > 0 && m < 0){
                count += nums[i];
                count += abs(m);
            }
            else{
                count += nums[i] - m;
            }
        }
        }
        return count;
    }
};