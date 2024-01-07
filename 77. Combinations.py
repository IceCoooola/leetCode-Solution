class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        num = [i for i in range(1, n + 1)]
        return self.helper(num, k)
        
    def helper(self, num, k):
        if k == 1:
            return [[e] for e in num]
        if len(num) == k:
            return [num]
        ret = []
        for i in range(len(num)):
            x = [num[i]]
            rest = self.helper(num[i+1:], k-1)
            for r in rest:
                ret.append(x + r)
        return ret
