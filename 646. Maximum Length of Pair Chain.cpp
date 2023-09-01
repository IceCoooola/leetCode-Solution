class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int sz = pairs.size();
        vector<int> dp(sz, 1);
        int ret = 1;
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > ret)
                ret = dp[i];
        }
        return ret;
    }
};
