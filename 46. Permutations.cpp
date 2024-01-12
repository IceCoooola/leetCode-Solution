class Solution {
public:

    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        ret = vector<vector<int>>();
        helper(nums, vector<int>());
        return ret;
    }

    void helper(vector<int>& nums, vector<int> tmp) {
        if (0 == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            vector<int> next(nums.begin(), nums.end());
            next.erase(next.begin() + i);
            helper(next, tmp);
            tmp.pop_back();
        }
    }
};
