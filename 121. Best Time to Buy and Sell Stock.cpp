class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = 0;
        int prof = 0;
        for(int i = 1; i< prices.size(); i++)
        {
            if(prices[i] - prices[idx] < 0)
            {
                idx = i;
            }
            else
            {
                if(prices[i] - prices[idx] > prof)
                    prof = prices[i] - prices[idx];
            }
        }
        return prof;
    }
};
