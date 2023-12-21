class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        [1 3] [6 9].  [2 5] newInterval[0] > cur[1]
        vector<vector<int>> ret;
        bool saved = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                ret.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0]) {
                if (saved) {
                    ret.push_back(intervals[i]);
                } else {
                    ret.push_back(newInterval);
                    ret.push_back(intervals[i]);
                    saved = true;
                }
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (find(ret.begin(), ret.end(), newInterval) == ret.end()) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};
