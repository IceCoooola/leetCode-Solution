class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        ret = []
        while left <= right:
            if abs(nums[left]) < abs(nums[right]):
                ret.append(nums[right] * nums[right])
                right -= 1
            else:
                ret.append(nums[left] * nums[left])
                left += 1
        ret.reverse()
        return ret
