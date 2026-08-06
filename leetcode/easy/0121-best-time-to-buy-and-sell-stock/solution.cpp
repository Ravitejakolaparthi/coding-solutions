class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int> bbuy(prices.size());
       bbuy[0] = prices[0];
       int sum = 0;
       for(int i = 1;i<prices.size();i++)
       {
            bbuy[i] = min(bbuy[i-1],prices[i]);
            sum = max(sum,abs(prices[i]-bbuy[i]));
      }
      
       return sum;
    }
};