class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n;
        n = nums[0];
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(n == nums[i+1])
            n = nums[i+1];
        }
        return n;

    }
};