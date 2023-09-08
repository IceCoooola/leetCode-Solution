class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int sz = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < sz; i++)
        {
            mp[arr[i]] = i;
        }
        int ret = 2;
        vector<vector<int>> dp(sz, vector<int>(sz, 2));
        for(int i = 1; i < sz; i++)
        {
            for(int j = i+1; j < sz; j++)
            {
                int e = arr[j] - arr[i];
                if(mp.count(e) && mp[e] < i)
                    dp[i][j] = dp[mp[e]][i] + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        if(ret >=3)
            return ret;
        else
            return 0;
    }
};
