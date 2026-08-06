class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mv = 0;
        for(int i=1;i<prices.size();i++)
        {
            mv += max(prices[i]-prices[i-1],0);
        }
        return mv;
    }
};