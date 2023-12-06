class Solution:
    matched = {}
    def isMatch(self, s: str, p: str) -> bool:
        print(s, p)
        if (s, p) in self.matched:
            return self.matched[(s, p)]
        elif len(s) == 0 and len(p) == 0:
            self.matched[(s, p)] = True
        elif len(s) == 0:
             self.matched[(s, p)] = len(p) / 2 == p.count("*")
        elif len(p) == 0:
            self.matched[(s, p)] = False
        elif len(p) > 1 and p[1] == '*':
            if p[0] == s[0] or p[0] == '.':
                self.matched[(s, p)] = Solution.isMatch(self, s, p[2:]) or Solution.isMatch(self, s[1:], p)
            else:
                self.matched[(s, p)] = Solution.isMatch(self, s, p[2:])
        elif p[0] == '.' or s[0] == p[0]:
            self.matched[(s, p)] = Solution.isMatch(self, s[1:], p[1:])
        elif p[0] != s[0]:
            self.matched[(s, p)] = False
        return self.matched[(s, p)]
