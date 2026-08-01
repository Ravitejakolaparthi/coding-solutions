class Solution {
public:
    map<int,int>mp;
    void mappush(int n)
    {
        if(mp.find(n) == mp.end())
        {
            mp[n] = 1;
        }
        else
        {
            mp[n]++;
        }
    }
    void mappop(int n)
    {
         mp[n]--;
       if(mp[n] == 0)
        mp.erase(n);
        // else/
     
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<k)
        return 0;
        long long sum = 0;
        vector<long long>v ={0};
        for(int i = 0;i<k;i++)
        {
            mappush(nums[i]);
            sum += nums[i];
        }  
        int i = 0;
        int j = k;
        if(mp.size() == k)
        v.push_back(sum);
        while(i < nums.size() && j < nums.size())
        {
            
                sum += nums[j];
                sum -= nums[i];
                mappush(nums[j]);
                mappop(nums[i]);
                i++;
                j++;
                if(mp.size() == k)
                v.push_back(sum);
            
        }
        return *max_element(v.begin(),v.end());
    }
};