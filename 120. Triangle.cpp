class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<vector<int>> dp(sz, vector<int>(sz+1, INT_MAX));
        dp[0][0+1] = triangle[0][0];
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j+1] = min(dp[i-1][j+1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int ret = INT_MAX;
        for(int i = 1; i <= sz; i++)
        {
            if(dp[sz-1][i] < ret)
                ret = dp[sz-1][i];
        }
        return ret;
    }
};
