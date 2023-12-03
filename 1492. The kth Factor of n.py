class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        factorFirst = []
        factorLast = []
        for i in range(1, floor(sqrt(i))):
            if n % i == 0:
                factorFirst.append(i)
                factorLast.append(n // i)
        if k > len(factorFirst):
            return -1
        else:
            return factors[k-1]
        
