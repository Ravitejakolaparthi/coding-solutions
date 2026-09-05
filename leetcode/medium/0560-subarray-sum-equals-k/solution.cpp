class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        int count  = 0;
        for(int i = 0;i<nums.size();i++){
            if(prefix[i] == k)
            count++;
        }
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(prefix[i]-prefix[j] == k)
                count++;
            }
        }
            return count;
    }
};