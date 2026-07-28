class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> a;
      int n = nums.size();
      int min = 999999;
      int minidx = -1;
      for(int i = 0;i<n;i++)
      {
        if(nums[i] >= 0 &&  nums[i] < min)
        {
            min = nums[i];
            minidx = i;
        }
      }  
      if(min == 999999)
      {
        minidx = n;
      }
      int j = minidx;
      int i = minidx -1;
      while(i >=0 && j < n)
      {
         if(pow(nums[i],2) > pow(nums[j],2))
         {
            a.push_back(pow(nums[j],2));
            j++;
         }
         else
         {
            a.push_back(pow(nums[i],2));
            i--;
         }
      }
      while(i >= 0)
      {
         a.push_back(pow(nums[i],2));
         i--;
      }
      while(j < n)
      {
        a.push_back(pow(nums[j],2));
        j++;
      }

      return a;
    }
};