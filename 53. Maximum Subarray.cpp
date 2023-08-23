class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz+1);
        int ret = INT_MIN;
        for(int i = 1; i <= sz; i++)
        {
            dp[i] = max(nums[i-1], nums[i-1] + dp[i-1]);
            if(dp[i] > ret)
                ret = dp[i];
        }
        return ret;
    }
};
