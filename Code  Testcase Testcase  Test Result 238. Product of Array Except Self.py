class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        n = len(nums)
        zero_count = 0
        for i in range(n):
            if nums[i] != 0:
                product *= nums[i]
            else:
                zero_count += 1
                if zero_count >= 2:
                    return [0] * n
        ret = []
        for e in nums:
            if e != 0 and zero_count >= 1:
                ret.append(0)
            elif e == 0:
                ret.append(product)
            else:
                ret.append(product // e)
        return ret
