class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // dp[i][j] -> maximum number of connecting lines draw between nums1[0, i=1] nums2[0, j-1]
        // if nums1[i-1] == nums2[j-1] -> 1 + dp[i-1][j-1]
        // else dp[i][j] = max dp[i-1][j] dp[i][j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
