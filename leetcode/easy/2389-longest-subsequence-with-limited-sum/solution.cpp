class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>prefix(n);
        sort(nums.begin(),nums.end());
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
       
        vector<int>b;
        if((prefix[0] > queries[0]) && queries.size()==1)
        {
            b.push_back(0);
            return b;
        }
        
        int cnt = 0;
        
        for(int i = 0;i<m;i++)
        {
            int val = queries[i];
            int sum = prefix[0];
            cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(prefix[j] > val)
                {
                  break;
                }
                // sum+=prefix[j];
                cnt++;
               
            }
            b.push_back(cnt);
        }
      return b;
    }
};