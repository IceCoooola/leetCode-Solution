class Solution:
    def integerBreak(self, n: int) -> int:
        # dp[i] = max product to get i.
        # dp[i] = dp[x] * dp[i-x] for x in range(1, i//2 + 1)
        dp = [0, 1]
        for i in range(2, n+1):
            dp.append(max(max(dp[x], x) * max(dp[i-x], i-x) for x in range(1, i//2 + 1)))
        return dp[-1]
