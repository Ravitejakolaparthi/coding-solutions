class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
       
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        v.push_back(nums[i]);
        for(int i=nums.size()-1;i>=0;i--)
        v.push_back(nums[i]);
        return v;   
    }
};