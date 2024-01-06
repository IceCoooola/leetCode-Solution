class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i - coin >= 0 && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if (amount == 0) return 0;
//         vector<int> dp(amount + 1, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; ++i) {
//             for (int j = i-1; j >=0; --j) {
//                 if (dp[j] != INT_MAX && find(coins.begin(), coins.end(), i-j) != coins.end()) {
//                     dp[i] = min(dp[i], dp[j] + 1);
//                 }
//             }
//         }
//         return dp[amount] == INT_MAX? -1: dp[amount];
//     }
// };
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(), coins.end(), greater<int>());
//         int ret = INT_MAX;
//         change(coins, amount, ret, 0, 0);
//         return ret == INT_MAX? -1: ret;
//     }

//     void change(vector<int>& coins, int amount, int& ret, int idx, int ttl) {
//         if (amount == 0) {
//             ret = min(ret, ttl);
//             return;
//         }
//         if (amount < 0 || idx >= coins.size()) return;
//         change(coins, amount - coins[idx], ret, idx, ttl + 1);
//         change(coins, amount, ret, idx + 1, ttl);
//     }
// };
