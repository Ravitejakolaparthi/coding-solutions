class NumArray {
public:
    // vector<int>nums;
    vector<int>p;
    NumArray(vector<int>& nums) {
        // this ->nums = nums;
        
        p.resize(nums.size());
        p[0]=nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            p[i] = p[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // int sum=0; 
       
        if(left > 0)
        return p[right] - p[left-1];
        else
        return p[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */