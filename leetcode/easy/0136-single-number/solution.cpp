class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        /*
        XOR cancels same numbers like 
        uses associative and commitative property
        ex -> 4 1 2 1 2
        here
        n = 4
        n = 4^1 diff so nothin happen
        n = 4^1^2    ""
        n = 4^1^2^1 here according to associative cancel takes place
        n = 4^2  
        n = 4^2^2  same cancle takes place
        n = 4
        */
        for(int i =0;i<nums.size();i++)
        {
            n^=nums[i];
        }
        return n;
        

    }
};