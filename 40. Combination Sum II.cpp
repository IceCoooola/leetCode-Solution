class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ret = vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        vector<int> tmp = vector<int>();
        combine(candidates, target, tmp, 0);
        return ret;
    }

    void combine(vector<int> candidates, int target, vector<int> tmp, int idx) {
        if (target == 0) {
            ret.push_back(tmp);
            return;
        }
        if (candidates.size() <= idx) return;
        if (target >= candidates[idx]) {
            tmp.push_back(candidates[idx]);
            combine(candidates, target - candidates[idx], tmp, idx+1);
            tmp.pop_back();
        }
        idx += 1;
        while (idx < candidates.size() && candidates[idx] == candidates[idx-1]) {
            idx += 1;
        }
        combine(candidates, target, tmp, idx);
    }
};
