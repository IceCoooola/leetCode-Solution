class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0: 
            return 0
        
        MAX = float(math.inf)
        dp = [MAX] * (amount + 1) # the minimum coin change used amount $i
        dp[0] = 0
        if 1 in coins:
            dp[1] = 1
        for i in range(2, amount + 1):
            for coin in coins:
                if i - coin >= 0 and dp[i-coin] != -1:
                    dp[i] = min(dp[i], dp[i-coin] + 1)
        if dp[amount] == MAX:
            return -1
        return dp[amount]
