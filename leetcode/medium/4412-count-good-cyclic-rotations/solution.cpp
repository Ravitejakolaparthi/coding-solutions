class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long int>firsts(n);
        vector<long long int>seconds(n);
        vector<long long int>prefix(n);
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i]; 
        }
        long long int a = 0;
        int k = 0;
        for(int i = (n/2)-1;i<n-1;i++){
            firsts[k] = prefix[i] - a;
            seconds[k] = prefix[n-1] - prefix[i] + a;
            a = prefix[k];
            k++;
        }
        //   for(int i = 0;i<firsts.size();i++){
        //     cout << prefix[i];
        // }
        int b = 0;
        for(int i = (n/2);i<n;i++){
            long long int c = firsts[b];
            firsts[i] = seconds[b];
            seconds[i] = c;
            b++;
        }
        int count= 0;
        for(int i = 0;i<n;i++){
              if(firsts[i] > seconds[i]){
                  count++;
              }
        }
        return count;
    }
};