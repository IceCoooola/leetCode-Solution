class Solution:
    def numTrees(self, n: int) -> int:
        # f[i] = number of unique bst from 1 to i.
        f = [0, 1, 2]
        for i in range(3, n+1):
            append_right = f[i-1]
            append_left = f[i-1]
            append_middle = sum(f[j] * f[i-j-1] for j in range(i-1))
            f.append(append_middle+append_left+append_right)
        return f[n]
