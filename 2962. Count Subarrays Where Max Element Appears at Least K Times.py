class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        # dp[i][j] = the sub array [i:j], number of max element appears.
        e = max(nums)
        n = len(nums)
        left, right, ret = 0,0,0
        while right < n:
            if nums[right] == e:
                k -= 1
            right += 1
            while k == 0:
                if nums[left] == e:
                    k += 1
                left += 1
            ret += left
        return ret
