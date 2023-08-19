class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int count = 1;
        int left = 0;
        int right = 1;
        while(right < nums.size())
        {
            if(count < 2 && nums[right] == nums[left])
            {
                count++;
                nums[++left] = nums[right];
                right++;
            }
            else if(nums[right] != nums[left])
            {
                nums[++left] = nums[right++];
                count = 1;
            }
            else{
                count++;
                right++;
            }
        }
        return left+1;
    }
};
