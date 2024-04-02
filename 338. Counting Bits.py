class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0]
        exp = 0
        for i in range(1, n+1):
            if i == 2**exp:
                dp.append(1)
                exp += 1
            else:
                dp.append(1 + dp[i - 2**exp])
        return dp
