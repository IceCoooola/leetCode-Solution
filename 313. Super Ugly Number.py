class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        prime_len = len(primes)
        idx = [0 for _ in range(prime_len)]
        dp = [1]
        while len(dp) < n:
            minimum = float(math.inf)
            for i, index in enumerate(idx):
                minimum = min(primes[i] * dp[index], minimum)
            dp.append(minimum)
            for i, index in enumerate(idx):
                if dp[-1] == primes[i] * dp[index]:
                    idx[i] += 1
        return dp[-1]
