class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                nums[i] = -1
        memo = {}
        prefix_sum = [nums[0]] # prefixsum[i] sum of [0:n+1]
        memo[nums[0]] = 0
        for i in range(1, n):
            next = prefix_sum[i-1] + nums[i]
            if next not in memo:
                memo[next] = i
            prefix_sum.append(next)
        ret = 0
        for i in range(n):
            if prefix_sum[i] == 0:
                ret = max(i + 1, ret)
            else:
                x = prefix_sum[i]
                ret = max(ret, i - memo[x])
        return ret
