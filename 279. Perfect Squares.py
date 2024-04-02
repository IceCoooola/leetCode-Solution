class Solution:
    def numSquares(self, n: int) -> int:
        # dp[i] = least # of perfect square sum up to i
        dp = [0, 1]
        squares = [1]
        for i in range(2, n+1):
            if round(sqrt(i)) == sqrt(i):
                dp.append(1)
                squares.append(i)
            else:
                dp.append(min(dp[i - square] + 1 for square in squares))
        return dp[-1]
      
# class Solution:
#     def numSquares(self, n: int) -> int:
#         # dp[i] = least # of perfect square sum up to i
#         dp = [0, 1]
#         squares = [i * i for i in range(1, int(sqrt(n)) + 1)]
#         for i in range(2, n+1):
#             if round(sqrt(i)) == sqrt(i):
#                 dp.append(1)
#             else:
#                 dp.append(min(dp[i - square] + 1 for square in squares if square < i))
#         return dp[-1]
