class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int ret = INT_MAX;
        change(coins, amount, ret, 0, 0);
        return ret == INT_MAX? -1: ret;
    }

    void change(vector<int>& coins, int amount, int& ret, int idx, int ttl) {
        if (amount == 0) {
            ret = min(ret, ttl);
            return;
        }
        if (amount < 0 || idx >= coins.size()) return;
        change(coins, amount - coins[idx], ret, idx, ttl + 1);
        change(coins, amount, ret, idx + 1, ttl);
    }
};
