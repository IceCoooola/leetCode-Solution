class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        ret = UFS()
        for num in nums:
            ret.add(num)

        for num in nums:
            if num-1 in ret.id:
                ret.union(num-1, num)
            if num+1 in ret.id:
                ret.union(num+1, num)
                
        return ret.max_count

class UFS:
    def __init__(self):
        self.id = {}
        self.count = {}
        self.max_count = 0

    def add(self, x):
        if x in self.id:
            return
        self.id[x] = x
        self.count[x] = 1
        self.max_count = 1

    def find(self, x):
        while x != self.id[x]:
            x = self.id[x]
        return x
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.count[x] < self.count[y]:
            x, y = y, x
        self.id[x] = y
        self.count[y] += self.count[x]
        self.max_count = max(self.count[y], self.max_count)
