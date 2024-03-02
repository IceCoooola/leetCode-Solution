class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        intervals.sort()
        new_interval = intervals[0]
        for interval in intervals:
            # [1,2] [3, 4]
            if new_interval[1] < interval[0]:
                ret.append(new_interval)
                new_interval = interval
            # [3, 4] [1, 2]
            elif new_interval[0] > interval[1]:
                ret.append(interval)
            else:
                # [1,3], [2,4]
                new_interval = [new_interval[0], max(interval[1], new_interval[1])]
        ret.append(new_interval)
        return ret
        
# class Solution:
#     def merge(self, intervals: List[List[int]]) -> List[List[int]]:
#         ret = []
#         if not intervals:
#             return ret
#         intervals.sort()
#         ret.append(intervals[0])
#         for pair in intervals:
#             found = False
#             if ret[-1][0] <= pair[0] <= ret[-1][1] or ret[-1][0] <= pair[1] <= ret[-1][1]:
#                 ret[-1][0] = min(ret[-1][0], pair[0])
#                 ret[-1][1] = max(ret[-1][1], pair[1])
#             else:
#                 ret.append(pair)
#         return ret
