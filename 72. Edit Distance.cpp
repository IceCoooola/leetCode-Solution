class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m == 0 || n == 0) return max(m,n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0x77bb77));
        // word1[0:i-1] -> word2[0:j-1]
        // dp[0][0] = word1[0] == word2[0]? 0 : 1;
        // dp[0][1] = (word1[0] == word2[1] || dp[0][0] == 0)? 1: 2;
        // dp[1][0] = (word1[1] == word2[0] || dp[0][0] == 0)? 1: 2;
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         if (word1 == word2) {
//             return 0;
//         }
//         if (word1 == "") return word2.size();
//         if (word2 == "") return word1.size();
//         int a = INT_MAX;
//         int sub = INT_MAX;
//         int insert = INT_MAX;
//         int replace = INT_MAX;
//         if (word1[0] == word2[0]) {
//             a = minDistance(word1.substr(1), word2.substr(1));
//         }
//         sub = 1 + minDistance(word1.substr(1), word2);
//         insert = 1 + minDistance(word1, word2.substr(1));
//         replace = 1 + minDistance(word1.substr(1), word2.substr(1));
//         int ret = a;
//         ret = ret < sub? ret: sub;
//         ret = ret < insert? ret: insert;
//         ret = ret < replace? ret: replace;
//         return ret;
//     }
// };
