class Solution {
public:
    int minCut(string s) {
        int sz = s.length();
        vector<vector<bool>> isPalindrome(sz, vector<bool>(sz));
        //[i+1][j-1]
        for(int i = sz-1; i >= 0; i--)
        {
            for(int j = i; j < sz; j++)
            {
                if(s[i] == s[j])
                {
                    if(i == j || i + 1 == j) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = isPalindrome[i+1][j-1];
                }
            }
        }
        vector<int> dp(sz, 0x7b7b7b);
        for(int i = 0; i < sz; i++)
        {
            if(isPalindrome[0][i])
                dp[i] = 0;
            else
            {
                for(int j = i; j > 0; j--)
                {
                    if(isPalindrome[j][i])
                    {
                        dp[i] = min(dp[j-1] + 1, dp[i]);
                    }
                }
            }
        }
        return dp[sz-1];
    }
};
