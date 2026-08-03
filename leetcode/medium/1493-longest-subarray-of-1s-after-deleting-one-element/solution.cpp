class Solution {
public:
    int expand(int idx,vector<int>&nums)
    {
        int count = 0;
        int idxcopy = idx;
        idx++;
        while(idx <nums.size() && nums[idx] !=0)
        {
            if(nums[idx] == 1)
            count++;
            idx++;
        }
        idx = idxcopy;
        idx--;
        while(idx>=0 && nums[idx]!=0)
        {
            if(nums[idx] == 1)
            count++;
            idx--;
        }
        return count;
    }
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        for(int i =0;i<nums.size();i++) if(nums[i] == 0) length++;
        if(length == 0) return nums.size()-1;
        length = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                length = max(length,expand(i,nums));
            }
        }
        return length;
    }
};