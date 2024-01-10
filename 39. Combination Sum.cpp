class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        ret = vector<vector<int>>();
        vector<int> c = vector<int>();
        combine(candidates, target, c);
        return ret;
    }
    void combine(vector<int> candidates, int target, vector<int> combination) {
        if (target == 0) {
            ret.push_back(combination);
            return;
        }
        if (target < 0 || candidates.size() == 0) return;
        combination.push_back(candidates.back());
        combine(candidates, target - candidates.back(), combination);
        combination.pop_back();
        candidates.pop_back();
        combine(candidates, target, combination);
    }
};
