class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0;
        int t = sum;
        for(int i=0;i<accounts.size();i++){
             t = sum;
             sum = 0;
            for(int j = 0;j<accounts[i].size();j++){
                    sum += accounts[i][j];
            }
            sum = max(sum,t);
            
        }
        return sum;
    }
};