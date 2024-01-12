class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums.size() == 1) return nums[0];
        while(right >= left) {
            int mid = (right + left) / 2;
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
