class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        left = 0
        n = len(nums)
        right = 1
        count = {}
        count[nums[0]] = 1
        ret = 1
        while right != n:
            if nums[right] not in count:
                count[nums[right]] = 0
            count[nums[right]] += 1
            while count[nums[right]] > k:
                count[nums[left]] -= 1
                left += 1
            ret = max(ret, right - left + 1)
            right += 1
        return ret
