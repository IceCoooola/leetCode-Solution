class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0;
        int right = nums.size() - 1;
        while (cur < right) {
            while (right > cur && nums[right] != 0) --right;
            while (cur < right && nums[cur] == 0) cur += 1;
            if (right != cur) {
                swap(nums[cur++], nums[right--]);
            }
        }

        if (cur < nums.size() && nums[cur] == 0) cur += 1;

        right = nums.size() - 1;
        
        while (cur < right) {
            while (right > cur && nums[right] != 1) --right;
            while (cur < right && nums[cur] == 1) cur += 1;
            if (right != cur) {
                swap(nums[cur++], nums[right--]);
            }
        }
    }
};
