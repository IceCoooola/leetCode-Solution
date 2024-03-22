class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # the number of combinations that make up that amount using coin index i.
        # i: amount
        # j: coins
        n = len(coins)
        coins.sort()
        dp = [[0]*(n) for i in range(amount + 1)]
        for i in range(n):
            dp[0][i] = 1
        for cur_amount in range(1, amount + 1):
            for idx in range(n):
                if cur_amount - coins[idx] >= 0:
                    dp[cur_amount][idx] += dp[cur_amount - coins[idx]][idx]
                if idx - 1 >= 0:
                    dp[cur_amount][idx] += dp[cur_amount][idx-1]
        return dp[amount][n-1]
