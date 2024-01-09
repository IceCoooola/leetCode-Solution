class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(t) == 0:
            return 1
        if len(s) == 0:
            return 0
        if s[0] == t[0]:
            return self.numDistinct(s[1:], t) + self.numDistinct(s[1:], t[1:])
        else:
            return self.numDistinct(s[1:], t)
