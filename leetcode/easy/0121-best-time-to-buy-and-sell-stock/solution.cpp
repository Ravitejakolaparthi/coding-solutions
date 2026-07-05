class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int> bsell(prices.size());
       bsell[0] = prices[0];
       for(int i = 1;i<prices.size();i++)
       {
            bsell[i] = min(bsell[i-1],prices[i]);
       }
       for(int i = 0;i<prices.size();i++)
       cout<< bsell[i];
       return 0;
    }
};