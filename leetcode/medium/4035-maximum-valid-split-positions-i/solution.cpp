class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
       int n = nums.size();
       if(n<2) return 0;
        vector<int>arr;
        int ans=0;
       for(int i = 0;i<n+1;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                else arr.push_back(nums[j]);
            }
            int score = 0;
            int m = arr.size();
            // for(int j = 0;j<m;j++){
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
            vector<int>suffix(m);
            vector<int>prefix(m);
            suffix[m-1] = arr[m-1];
            prefix[0] = arr[0];
            for(int j = 1;j<m;j++){
                prefix[j] = __gcd(prefix[j-1],arr[j]);
            }
            for(int j = m-2;j>=0;j--){
                suffix[j] = __gcd(suffix[j+1],arr[j]);
            }
            // for(int j = 0;j<m;j++){
            //     cout << prefix[j] << " ";
            // }
            // cout << endl;
            // for(int j = 0;j<m;j++){
            //     cout << suffix[j] << " ";
            // }
            // cout << endl;
            for(int j = 0;j<m-1;j++){
                if(prefix[j] == suffix[j+1]){
                    score++;
                }
            }
            ans = max(ans,score);
            arr.clear();

       }
       return ans;
       
        
        
    }
};