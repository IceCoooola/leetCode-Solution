class Solution:
    def customSortString(self, order: str, s: str) -> str:
        mp = {}
        for c in s:
            if c not in mp:
                mp[c] = 0
            mp[c] += 1
        ret = ""
        for c in order:
            if c in mp:
                ret += c * mp[c]
                mp[c] = 0
        for c, count in mp.items():
            if count != 0:
                ret += c *count
        return ret
