//f[i][j] represent: when complete [j]th transaction, the maximum profit at the status of holding a stock.
//g[i][j] represent: when complete [j]th transaction, the maximum profit at the status of not holding a stock.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int sz = prices.size();
        vector<vector<int>> f(sz, vector<int>(k+1, -0x3f3f3f3f));
        vector<vector<int>> g(sz, vector<int>(k+1, -0x3f3f3f3f));
        f[0][0] = -prices[0];
        g[0][0] = 0;
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < k+1; j++)
            {
                f[i][j] = max(f[i-1][j], g[i-1][j] - prices[i]);
                g[i][j] = g[i-1][j];
                if(j > 0)
                    g[i][j] = max(g[i][j], f[i-1][j-1]+prices[i]);
            }
        }
        int max = -0x3f3f3f3f;
        for(int i = 0; i < k+1;i++)
        {
            if(g[sz-1][i] > max)
                max = g[sz-1][i];
        }
        return max;
    }
};
