class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] = t1[0:i] t2[0:j] 
        // t1[i] == t2[j]  -> dp[i-1][j-1]
        // t1[i] != t2[j] ->dp[i-1][j] dp[i][j-1] dp[i-1][j-1] max
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         // dp[i][j] = t1[0:i] t2[0:j] 
//         // t1[i] == t2[j]  -> dp[i-1][j-1]
//         // t1[i] != t2[j] ->dp[i-1][j] dp[i][j-1] dp[i-1][j-1] max
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//         for (int i = 1; i < m + 1; ++i) {
//             for (int j = 1; j < n + 1; ++j) {
//                 if (text1[i-1] == text2[j-1]) {
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 } else {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                     dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };
