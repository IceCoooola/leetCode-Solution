class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 2));
        int ret = 2;
        mp[nums[0]] = 0;
        for(int i = 1; i < sz; i++)
        {
            for(int j = i+1; j < sz; j++)
            {
                int e = 2 * nums[i] - nums[j];
                if(mp.count(e)){    
                    dp[i][j] = dp[mp[e]][i] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
            mp[nums[i]] = i;
        }
        return ret;
    }
};

// not working:
// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int sz = nums.size();
//         vector<vector<int>> dp(sz, vector<int>(sz, 2));
//         int ret = 2;
//         for(int i = 0; i < sz; i++){
//             mp[nums[i]] = i;
//         }

//         for(int i = 1; i < sz; i++)
//         {
//             for(int j = i+1; j < sz; j++)
//             {
//                 int e = 2 * nums[i] - nums[j];
//                 if(mp.count(e) && mp[e] < i){    
//                     dp[i][j] = dp[mp[e]][i] + 1;
//                 }
//                 cout<<"nums[i] = " << nums[i] << ", nums[j] = "<<nums[j]<<". dp[i][j] = "<<dp[i][j]<<endl;
//                 ret = max(ret, dp[i][j]);
//             }
//         }
//         return ret;
//     }
// };
