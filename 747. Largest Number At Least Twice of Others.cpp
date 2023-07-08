class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[max])
            {
                max = i;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(i != max && nums[max] < nums[i] * 2)
            {
                return -1;
            }
        }
        return max;
    }
};
