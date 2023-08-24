class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz);
        int sum = 0;
        for(int i = 2; i < sz; i++)
        {
            dp[i] = nums[i] - nums[i-1] == nums[i-1] - nums[i-2]? dp[i-1] + 1 : 0;
            sum += dp[i];
        }
        return sum;
    }
};
