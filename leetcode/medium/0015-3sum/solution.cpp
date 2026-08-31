class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>a;
             sort(nums.begin(),nums.end());
        int i = 0,j = 1,k = nums.size()-1;
        while(i < k-1)
        {
            while(j < k)
            {
                int b= nums[i]+ nums[j]+nums[k];
                int a1 = nums[i];
                int a2 = nums[j];
                int a3 = nums[k];
                if(b == 0)
                {
                    a.push_back({a1,a2,a3});
                    j++;
                    k--;
                }
                else if(b> 0)
                {
                    k--;
                }
                else if(b< 0)
                {
                    j++;
                }
            }
           
            i++;
            j = i+1;
            k = nums.size()-1;
            
        }
            sort(a.begin(),a.end());
            a.erase(unique(a.begin(),a.end()),a.end());
           return a;
    }
 
};