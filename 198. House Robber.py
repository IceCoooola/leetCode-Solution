
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        dp = [0] * 3 # maximum amount can rob
        dp[0] = nums[0]
        dp[1] = max(nums[1], nums[0])
        dp[2] = max(nums[1], nums[0])
        for i in range(2, len(nums)):
            dp[2] = max(dp[1], nums[i] + dp[0])
            dp[0] = dp[1]
            dp[1] = dp[2]
        return dp[2]


# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         if len(nums) == 1:
#             return nums[0]
#         dp = [0]*(len(nums)) # maximum amount can rob
#         dp[0] = nums[0]
#         dp[1] = max(nums[1], nums[0])
#         for i in range(2, len(nums)):
#             dp[i] = dp[i-1]
#             if i - 2 >= 0:
#                 dp[i] = max(dp[i], nums[i] + dp[i-2])
#         return dp[len(nums)-1]
