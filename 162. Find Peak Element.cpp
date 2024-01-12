class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        int idx = 1;
        while (idx < nums.size() - 1) {
            if (nums[idx] > nums[idx-1] && nums[idx] > nums[idx+1]) return idx;
            idx++;
        }
        return nums.size() - 1;
    }
    
};
