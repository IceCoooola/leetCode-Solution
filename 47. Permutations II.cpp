class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ret = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        helper(nums, vector<int>());
        return ret;
    }

    void helper(vector<int> nums, vector<int> tmp) {
        if (nums.size() == 0) {
            ret.push_back(tmp);
            return;
        }
        int i = 0;
        while (i < nums.size()) {
            int x = nums[i];
            tmp.push_back(x);
            vector<int> next(nums.begin(), nums.end());
            next.erase(next.begin() + i);
            helper(next, tmp);
            tmp.pop_back();
            while (i < nums.size() && nums[i] == x) {
                i+=1;
            }
        }
        
    }
};
