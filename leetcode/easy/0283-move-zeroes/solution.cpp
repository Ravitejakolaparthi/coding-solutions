class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t = 0;
        auto it = remove(nums.begin(),nums.end(),t);
        fill(it,nums.end(),0);
    }
};