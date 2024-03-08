class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        arr = [0] * 101
        for x in nums:
            arr[x] += 1
        largest = max(arr)
        ret = 0
        for i in range(101):
            if arr[i] == largest:
                ret += arr[i]
        return ret
