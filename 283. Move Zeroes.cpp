class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while(fast < nums.size() && slow < nums.size())
        {
            while(fast < nums.size() && nums[fast] == 0)
                fast++;
            while(slow < nums.size() && nums[slow] != 0)
                slow++;
            if(fast == nums.size() || slow == nums.size())
                break;
            if(fast > slow)
            {
                nums[slow] = nums[fast];
                nums[fast] = 0;        
            }
            else
            {
                fast++;
            }
        }
    }
};
