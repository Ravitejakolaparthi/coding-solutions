class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1]; 
        for(int i= 1;i<nums.size();i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i= nums.size()-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1]+nums[i];
        }
        int idx = -1;
        for(int i =0;i<nums.size();i++)
        {
            if(suffix[i] == prefix[i])
            {
               idx = i;
               break;
            }
        }
        return idx;

    }
};