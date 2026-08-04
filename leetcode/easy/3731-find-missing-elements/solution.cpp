class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> miss;

        for(int i = 1; i < nums.size(); i++) {
        
            if(nums[i] - nums[i - 1] > 1) {
                for(int x = nums[i - 1] + 1; x < nums[i]; x++) {
                    miss.push_back(x);
                }
            }
        }
        return miss;
    }
};