class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int size = 99999999;
        int back = 0 , front = 0;
        while(front < nums.size()){
            sum += nums[front];
            while(sum >= target){
                size = min(size,abs(front-back+1));
                sum-=nums[back];
                back++; 
            }
            front++;
        }
        if(size == 99999999)
        return 0;
        else
        return size;
    }
};