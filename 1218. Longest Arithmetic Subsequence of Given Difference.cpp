class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int sz = arr.size();
        map<int, int> dp;
        dp[arr[0]] = 1;
        int ret = 1;
        for(int i = 1; i < sz; i++)
        {
            int e = arr[i];
            int target = e - difference;
            dp[e] = dp[target] + 1;
            ret = max(ret, dp[e]);
        }
        return ret;
    }
};
