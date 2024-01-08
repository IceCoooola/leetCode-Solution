class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 0x77bb77;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (right > left) {
                int sum = nums[left] + nums[right] + nums[i];
                if (target == sum) {
                    return target;
                }

                ret = abs(sum - target) < abs(ret - target)? sum : ret;
                if (sum < target) left++;
                else right--;
            }
        }
        return ret;
    }
};
