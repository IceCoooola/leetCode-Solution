class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = vector<vector<int>>(); 
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int sum = - nums[i];   
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == sum) {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    ret.push_back(tmp);
                    ++left;
                    --right;
                    while (left < n && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (right > 0 && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
                else if (nums[left] + nums[right] < sum) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return ret;
    }
};
