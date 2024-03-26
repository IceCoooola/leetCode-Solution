class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # dp[i][j] = max porfit burst baloons between i and j.
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        # dp[i][j] = consider k as the last baloon bursted between i and j.
        # for k in range(i+1, j):
        #   dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k])
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                for k in range(i+1, j):
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k])
        return dp[0][n-1]
