class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m = len(dungeon)
        n = len(dungeon[0])
        # dp(i, j) = minimum initial health needed starting from i j.
        @lru_cache
        def dp(i, j) -> int:
            # base case, if at the lower right coner
            if i == m-1 and j == n-1:
                return max(1, -dungeon[i][j] + 1)
            # other case, when end not reached
            ret = float(math.inf)
            if i < m-1:
                ret = min(dp(i + 1, j) - dungeon[i][j], ret)
            if j < n-1:
                ret = min(dp(i, j + 1) - dungeon[i][j], ret)
            ret = max(ret, 1)
            return ret
        return dp(0,0)
