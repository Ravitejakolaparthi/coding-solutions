class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_go = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i > can_go)
            return false;
            can_go = max(can_go,i+nums[i]);
        }
        // can_go +=1;
        return true;
    
    }
};