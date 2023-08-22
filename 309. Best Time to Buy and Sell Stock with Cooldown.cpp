class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<vector<int>> dp(sz, vector<int>(3));
        // 0 == buy.  1 == able to buy.  2 == coolDown
        dp[0][0] = -prices[0];
        for(int i = 1; i < sz; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][2], dp[i-1][1]);
            dp[i][2] = dp[i-1][0] + prices[i];
        }
        return max(dp[sz-1][1], dp[sz-1][2]);
    }
};
