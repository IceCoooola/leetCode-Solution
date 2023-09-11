class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length();
        //dp表：以i, j位置为开头和结尾的最长回文子串的长度，i <= j
        //需要用到：i+1, 和j-1位置的元素
        vector<vector<int>> dp(sz, vector<int>(sz));
        int ret = 1;
        int start = 0;
        for(int i = sz-1; i >= 0; i--)
        {
            for(int j = i; j < sz; j++)
            {
                if(s[i] == s[j])
                {
                    if(i == j)
                        dp[i][j] = 1;
                    else if(i + 1 == j)
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        if(dp[i+1][j-1])
                            dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }
                if(dp[i][j] > ret)
                {
                    ret = dp[i][j];
                    start = i;
                }
            }
        }
        return s.substr(start, ret);
    }
};
