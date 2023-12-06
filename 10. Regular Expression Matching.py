class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s) == 0 and len(p) == 0:
            return True
        if len(s) == 0:
            return (len(p) / 2 == p.count("*"))
        if len(p) == 0:
            return False
        if len(p) > 1 and p[1] == '*':
            if p[0] == s[0] or p[0] == '.':
                return Solution.isMatch(self, s, p[2:]) or Solution.isMatch(self, s[1:], p)
            return Solution.isMatch(self, s, p[2:])
        if p[0] == '.' or s[0] == p[0]:
            return Solution.isMatch(self, s[1:], p[1:])
        return False
