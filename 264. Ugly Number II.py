class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = []
        dp.append(1)
        idx_2 = 0
        idx_3 = 0
        idx_5 = 0
        while len(dp) < n:
            dp.append(min(dp[idx_2] * 2, dp[idx_3] * 3, dp[idx_5] * 5))
            if dp[idx_2] * 2 == dp[-1]: idx_2 += 1
            if dp[idx_3] * 3 == dp[-1]: idx_3 += 1
            if dp[idx_5] * 5 == dp[-1]: idx_5 += 1
        return dp[n-1]
