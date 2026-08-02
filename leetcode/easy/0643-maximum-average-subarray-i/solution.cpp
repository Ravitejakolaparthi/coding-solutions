class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        for(int i = 0;i<k;i++)
        {
            avg += nums[i];
        }
        double curravg = avg;
        for(int i = k;i<nums.size();i++)
        {
            avg += double(nums[i]);
            avg -= double(nums[i-k]);
            curravg = max(curravg,avg);
        }
        return curravg/k;
    }
};