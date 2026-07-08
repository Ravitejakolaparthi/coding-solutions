class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (nums.size()*(nums.size()+1)/2);
        for(int i = 1;i<nums.size();i++)
        {
            nums[0] += nums[i]; 
        }
        return n-nums[0];

    }
};