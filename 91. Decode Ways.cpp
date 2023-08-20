class Solution {
public:
    int numDecodings(string s) {
        int sz = s.length();
        vector<int> dp(sz+1);
        dp[0] = 1;
        dp[1] = s[1 - 1] != '0';
        for(int i = 2; i <= sz; i++)
        {
            if(s[i-1] != '0') dp[i] += dp[i-1];
            int t = (s[i-2] -'0') * 10 + s[i-1] -'0';
            if(t <= 26 && t >=10) dp[i] += dp[i-2];
        }
        return dp[sz];
    }
};


// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<int> dp(s.length());
//         if(s[0] == '0')
//             return 0;
//         else
//             dp[0] = 1;
//         if(s.length() > 1)
//         {
//             int code = (s[0]-'0') * 10 + s[1]-'0';
//             if(s[1] != '0')
//             {
//                 dp[1] = 1;
//             if(code <= 26 && code > 10 && code != 20)
//             {
//                 dp[1] = 2;
//             }
//             }
//             else{
//                 if(code == 20 || code == 10)
//                 dp[1] = 1;
//             }
//         }
//         for(int i = 2; i < dp.size(); i++)
//         {
//             int ttl = 0;
//             if(s[i] - '0' != 0)
//             {
//                 ttl += dp[i-1];
//             }
//             int code = (s[i-1]-'0') * 10 + s[i]-'0';
//             if(code <= 26 && code >= 10)
//             {
//                 ttl += dp[i-2];
//             }
//             dp[i] = ttl;
//         }
//         return dp[s.length()-1];
//     }
// };
