class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums[0];
        int f = 0;
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size()-1;i+=2)
        {
              if(nums[i-1]^nums[i] != 0)
              {
                 if(i != nums.size())
                 {
                 f = 1;
                 n = nums[i-1];
                 }
              }
             
        }
        if(f == 0)
        {
            n = nums[nums.size()-1];
        }

        return n;

    }
};