class Solution {
public:
    map<int,int>mp;
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        int j = 0;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp[0]>1)
            {
                mp[nums[j]]--;
                j++;
            }
            length = max(i-j+1,length);
        }
        return length-1;
    }
};