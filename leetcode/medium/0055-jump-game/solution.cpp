class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
        return true;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] >= nums.size()-1)
            return true;
            if(nums[i]<=0)
            return false;
        }
        return true;
    }
};