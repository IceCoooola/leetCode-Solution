class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size();
        vector<int> d(sz);
        vector<int> p(sz);
        d[0] = -prices[0];
        for(int i = 1; i < sz; i++)
        {
            d[i] = max(d[i-1], p[i-1]-prices[i]);
            p[i] = max(p[i-1], d[i-1] + prices[i] - fee);
        }
        return max(d[sz-1], p[sz-1]);
    }
};
