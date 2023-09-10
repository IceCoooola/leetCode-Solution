class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.length();
        int ret = 0;
        vector<vector<int>> dp(sz, vector<int>(sz));
        for(int i = sz-1; i >= 0; i--)
        {
            for(int j = i; j < sz; j++)
            {
                if(s[i] == s[j])
                {  
                    if(i == j || i+1 == j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i+1][j-1]; 
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};
