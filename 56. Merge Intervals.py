class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        if not intervals:
            return ret
        intervals.sort()
        ret.append(intervals[0])
        for pair in intervals:
            found = False
            if ret[-1][0] <= pair[0] <= ret[-1][1] or ret[-1][0] <= pair[1] <= ret[-1][1]:
                ret[-1][0] = min(ret[-1][0], pair[0])
                ret[-1][1] = max(ret[-1][1], pair[1])
            else:
                ret.append(pair)
        return ret
