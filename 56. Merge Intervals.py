class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        intervals.sort()
        for pair in intervals:
            found = False
            for i in range(len(ret)):
                if ret[i][0] <= pair[0] <= ret[i][1] or ret[i][0] <= pair[1] <= ret[i][1]:
                    ret[i][0] = min(ret[i][0], pair[0])
                    ret[i][1] = max(ret[i][1], pair[1])
                    found = True
                    break
            if not found:
                ret.append(pair)
        return ret
