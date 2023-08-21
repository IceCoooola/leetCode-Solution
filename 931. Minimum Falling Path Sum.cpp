class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+2));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = matrix[i-1][j-1] + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i-1][j+1]);
            }
            dp[i][0] = dp[i][1];
            dp[i][n+1] = dp[i][n];
        }
        int ret = dp[m][0];
        for(int j = 1; j <= n; j++)
        {
            if(dp[m][j] < ret)
                ret = dp[m][j];
        }
        return ret;
    }
};
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         if(matrix.size() == 1 && matrix[0].size() == 1)
//             return matrix[0][0];
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m+1, vector<int>(n));
//         for(int i = 1; i <= m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(j == 0)
//                 {
//                     dp[i][j] = matrix[i-1][j] + min(dp[i-1][0], dp[i-1][1]);
//                 }
//                 else if(j == n - 1)
//                 {
//                     dp[i][j] = matrix[i-1][j] + min(dp[i-1][n-1], dp[i-1][n-2]);
//                 }
//                 else
//                 {
//                     dp[i][j] = matrix[i-1][j] + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i-1][j+1]);
//                 }
//             }
//         }
//         int ret = dp[m][0];
//         for(int j = 0; j < n; j++)
//         {
//             if(dp[m][j] < ret)
//                 ret = dp[m][j];
//         }
//         return ret;
//     }
// };
