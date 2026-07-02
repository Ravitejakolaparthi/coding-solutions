class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = 2*nums.size();
        vector<int>v(n);
        for(int i=0;i<nums.size();i++)
        v.push_back(v[i]);
        for(int i=nums.size()-1;i>=0;i--)
        v.push_back(v[i]);
        return v;   
    }
};