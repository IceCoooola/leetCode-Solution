class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int sz = s.length();
        vector<int> dp(sz, 1);
        int arr[26] = {0}; 
        arr[s[0] - 'a'] = 1;
        for(int i = 1; i < sz; i++)
        {
            if(s[i] - s[i-1] == 1)
                dp[i] = dp[i-1] + 1;
            if(s[i] == 'a' && s[i-1] == 'z')
                dp[i] = dp[i-1] + 1;
            arr[s[i] - 'a'] = max(dp[i], arr[s[i]-'a']);
        }
        int ret = 0;
        for(int i = 0; i < 26; i++)
        {
            ret += arr[i];
        }
        return ret;
    }
};
