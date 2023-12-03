class Solution:
    def partitionString(self, s: str) -> int:
        partition = ''
        ret = 0
        for letter in s:
            if letter in partition:
                partition = ""
                ret += 1
            partition += letter
        return ret + 1
