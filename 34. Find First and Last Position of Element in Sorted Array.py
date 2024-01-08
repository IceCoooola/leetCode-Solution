class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        left = 0
        n = len(nums)
        right = n - 1
        while right >= left:
            mid = (left + right) // 2
            if nums[mid] == target:
                right = left = mid
                while right + 1 < n and nums[right + 1] == target:
                    right += 1
                while left - 1 >= 0 and nums[left - 1] == target:
                    left -= 1
                return [left, right]
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
        return [-1, -1]
