class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int sz = arr.size();
        unordered_map<long long, vector<int>> mp;
        for(int i = 0; i < sz; i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>> dp(sz, vector<int>(sz));
        int ret = 0;
        for(int j = 2; j < sz; j++)
        {
            for(int i = 1; i < j; i++)
            {
                long long e = (long long)2 * arr[i] - arr[j];
                if(mp.count(e))
                {
                    for(auto k: mp[e])
                    {
                        if(k < i)
                            dp[i][j] += dp[k][i] + 1;
                    }
                }
                ret+=dp[i][j];
            }
            
        }
        return ret;
    }
};
