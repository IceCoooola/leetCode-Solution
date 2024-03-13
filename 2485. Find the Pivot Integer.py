class Solution:
    def pivotInteger(self, n: int) -> int:
        for x in range(n, 0, -1):
            first_half = (1 + x) * x / 2
            second_half = (x + n) * (n-x+1) / 2
            if first_half == second_half:
                return x
        return -1
