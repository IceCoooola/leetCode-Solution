class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < nums.size() && right > left)
        {
            if(nums[left] == val)
            {
                swap(nums[left], nums[right--]);
            }
            else
            {
                left++;
            }
        }
        if(nums[right] == val)
            return right;
        else
            return right+1;
    }
};
