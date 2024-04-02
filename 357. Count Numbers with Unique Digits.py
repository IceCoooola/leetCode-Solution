class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        # f(n) = count of number with unique digits of length n.
        if n == 0:
            return 1
        f = [0, 10, 81]
        for i in range(3, n+1):
            f.append(f[i-1] * (10-i+1))
        return sum(f[:n+1])
