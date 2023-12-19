class Solution {
public:
    // 2   3   1   1.  4
    // 2   1   inf  1
    // dp[i] the minimum step to reach last position from i th position.
    // dp[i] = 1 + min(dp[j] where can reach)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0x77ff77);
        dp[n-1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[0];
    }
};
