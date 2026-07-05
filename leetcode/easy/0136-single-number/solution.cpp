class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n;
        sort(nums.begin(),nums.end());
        n = nums[0];
        for(int i = 1;i<nums.size()-1;i++)
        {
            if(n == nums[i])
            n = nums[i+1];
        }
        return n;

    }
};