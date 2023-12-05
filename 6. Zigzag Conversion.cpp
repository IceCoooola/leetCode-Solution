class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        # first row: 
        # from idx 0 till end with + 2 *numRows - 2 increment
        ret = ""
        skip = 2 * numRows - 2
        # first row
        for i in range(0, len(s), skip):
            ret += s[i]
        # rows inside
        for i in range(1, numRows - 1):
            for j in range(i, len(s), skip):
                ret += s[j]
                if j + (numRows - i) + (numRows - 2) - i < len(s):
                    ret += s[j +(numRows - i) + (numRows - 2) - i]
        for i in range(numRows - 1, len(s), skip):
            ret += s[i]
        return ret
