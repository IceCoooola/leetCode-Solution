class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        n = len(croakOfFrogs)
        dp = [0,0,0,0,0]
        ret = 0
        maxFrog = 0
        if croakOfFrogs[-1] != 'k':
            return -1
        for i in range(n):
            if croakOfFrogs[i] == 'c':
                dp[0] += 1
                maxFrog += 1
            elif croakOfFrogs[i] == 'r':
                dp[0] -= 1
                dp[1] += 1
            elif croakOfFrogs[i] == 'o':
                dp[1] -= 1
                dp[2] += 1
            elif croakOfFrogs[i] == 'a':
                dp[2] -= 1
                dp[3] += 1
            elif croakOfFrogs[i] == 'k':
                dp[3] -= 1
                dp[4] += 1
                maxFrog -= 1
            ret = max(maxFrog, ret)
            if -1 in dp:
                return -1
        for i in range(4):
            if dp[i] != 0:
                return -1
        return ret
