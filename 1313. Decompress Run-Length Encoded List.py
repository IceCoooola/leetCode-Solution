class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        return nums[0] * [nums[1]] + self.decompressRLElist(nums[2:])
