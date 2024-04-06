class Solution:
    def knightDialer(self, n: int) -> int:
        next_move = {}
        next_move[0] = [4, 6]
        next_move[1] = [6, 8]
        next_move[2] = [7, 9]
        next_move[3] = [4, 8]
        next_move[4] = [3, 9, 0]
        next_move[5] = []
        next_move[6] = [1, 7, 0]
        next_move[7] = [6, 2]
        next_move[8] = [1, 3]
        next_move[9] = [2, 4]

        # dp[n][i] = how many possible knight move n digits ending at i.
        dp = [[0,0,0,0,0,0,0,0,0,0] for _ in range(n+1)]
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1
        for x in range(2, n+1):
            for i in range(10):
                dp[x][i] = (sum(dp[x-1][t] for t in next_move[i]) % 1000000007)
        return (sum(dp[n][i] for i in range(10)) % 1000000007)
