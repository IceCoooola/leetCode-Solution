class Solution {
public:
    int minInsertions(string s) {
        // [i] [j] -> minimum steps to make s[i:j+1] parlindrome
        
        // s[i] == s[j] : dp[i][j] = dp[i-1][j-1]
        // s[i] != s[j] : min(dp[i-1][j], dp[i][j-1]) + 1
        // i == j -> 0
        // 
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    dp[i][j] = 0;
                }
                else if (j == i+1) {
                    dp[i][j] = s[i] == s[j]? 0 : 1;
                }
                else if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
};
