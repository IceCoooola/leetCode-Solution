
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False]*(n+1) for _ in range(m+1)]
        dp[0][0] = True

        for j in range(1, n+1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-1]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] == p[j-1] or p[j-1] == '?':
                    dp[i][j] = dp[i][j] or dp[i-1][j-1]
                elif p[j-1] == '*':
                    for t in range(i, -1, -1):
                        if dp[t][j-1] == True:
                            dp[i][j] = True
                            break
        return dp[m][n]


# @lru_cache
# class Solution:
#     def isMatch(self, s: str, p: str) -> bool:
#         if s == "" and p == "":
#             return True
#         if s == "" and p[-1] == "*":
#             return self.isMatch(s, p[:-1])
#         if s == "" or p == "":
#             return False
#         if s[-1] == p[-1] or p[-1] == '?':
#             return self.isMatch(s[:-1], p[:-1])
#         elif p[-1] == '*':
#             for x in range(len(s)+1):
#                 if self.isMatch(s[:x], p[:-1]):
#                     return True
#             return False
#         else:
            # return False
