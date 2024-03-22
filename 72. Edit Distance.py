from functools import lru_cache 
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        # top_down(i, j) = minimum edit distance to convert i char of word1 to j char of word2
        @lru_cache
        def top_down(i, j):
            if i == 0:
                return j
            if j == 0:
                return i 
            replace, remove, insert = 0, 0, 0
            if word1[i-1] == word2[j-1]:
                return top_down(i-1, j-1)
            replace = top_down(i-1, j-1) + 1
            remove = top_down(i-1, j) + 1
            insert = top_down(i, j-1) + 1
            return min(replace, remove, insert)
        return top_down(len(word1), len(word2))
