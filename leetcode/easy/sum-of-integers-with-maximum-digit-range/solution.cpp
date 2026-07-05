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
                 // cout << s <<endl;
                l = max(l,rem);
                 // cout << l <<endl;
                n = n/10; 
             }
        int r = l-s;
        return r;
       
    }
    
    int maxDigitRange(vector<int>& nums) {
       
        int m = -1;
        for(int i = 0;i<nums.size();i++)
            { 
                m = max(m,rangeof(nums[i]));
            }
            cout << m;
           
        
        return 1;
    }
};