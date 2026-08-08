class Solution {
public:
    int jump(vector<int>& nums) {
        int Jumps = 0;
        int How_Far = 0;
        int Max_Far = How_Far;
        for(int i = 0;i<nums.size()-1;i++)
        {
            Max_Far = max(Max_Far,i+nums[i]);
            if(i == How_Far)
            {
                Jumps++;
                How_Far = Max_Far;
            }  
              
        }
        return Jumps;
    }
};