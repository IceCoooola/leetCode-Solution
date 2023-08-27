class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1);
        int ret = 1;
        for(int i = 1; i < sz; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
