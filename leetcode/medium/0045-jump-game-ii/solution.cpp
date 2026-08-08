class Solution {
public:
    int jump(vector<int>& nums) {
        int can_go = nums[0];
        int Jumps = 0;
        for(int i = 1;i<nums.size();i++){
            if(can_go < nums.size())
            {
                Jumps++;
            }
            can_go = max(can_go,i+nums[i]);
        }
        return Jumps;
    }
};