class Solution {
public:
    int rangeof(int n)
    {
        vector<int>v;
         int s = 999999;
         int l = -1;
         int rem = 0;
         while(n>0)
             {
                rem = n%10;
                s = min(s,rem);
                 cout << s <<endl;
                l = max(s,rem);
                 cout << l <<endl;
                n = n/10; 
             }
        int r = l-s;
        return r;
       
    }
    
    int maxDigitRange(vector<int>& nums) {
        vector<int>v(nums.size());
        for(int i = 0;i<nums.size();i++)
            {
                v[i] = rangeof(nums[i]);  
            }
            for(int i = 0;i<v.size();i++)
                cout << v[i];
        return 1;
    }
};