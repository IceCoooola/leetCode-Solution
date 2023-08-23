class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz + 1);
        int ret = INT_MIN;
        int sum = 0;
        for(int i = 1; i <= sz; i++)
        {
            sum+= nums[i-1];
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]);
            if(dp[i] > ret)
                ret = dp[i];
        }
        int small = INT_MAX;
        for(int i = 1; i <= sz; i++)
        {
            dp[i] = min(nums[i-1], dp[i-1] + nums[i-1]);
            if(dp[i] < small)
                small = dp[i];
        }
        if(small == sum)
            return ret;
        else
            return sum - small > ret? sum - small: ret;
    }
};
