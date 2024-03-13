from functools import lru_cache
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        m = len(s1)
        n = len(s2)
        @lru_cache
        def top_down(i, j): # use i character from s1 and j character from s2 to construct s3.
            if i == 0 and j == 0:
                return True
            if i == 0: 
                return s2[:j] == s3[:i+j]
            if j == 0:
                return s1[:i] == s3[:i+j]
            ret = False
            if s1[i-1] == s3[i+j-1]:
                ret = ret or top_down(i-1, j)
            if s2[j-1] == s3[i+j-1]:
                ret = ret or top_down(i, j-1)
            return ret
        return top_down(m,n)
        # use i character from s1 and j character from s2 to construct s3.
