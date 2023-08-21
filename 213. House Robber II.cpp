class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        int sz = nums.size();
        vector<int> robPrev(sz);
        vector<int> NoRobPrev(sz);
        robPrev[2] = nums[2];
        for(int i = 2; i < sz - 1; i++)
        {
            robPrev[i] = NoRobPrev[i-1] + nums[i];
            NoRobPrev[i] = max(NoRobPrev[i-1], robPrev[i-1]);
        }
        int RobFirst = max(NoRobPrev[sz-2], robPrev[sz-2]) + nums[0];
        robPrev[1] = nums[1];
        for(int i = 1; i < sz; i++)
        {
            robPrev[i] = NoRobPrev[i-1] + nums[i];
            NoRobPrev[i] = max(NoRobPrev[i-1], robPrev[i-1]);
        }
        int NoRobFirst = max(NoRobPrev[sz-1], robPrev[sz-1]);
        return max(RobFirst, NoRobFirst);
    }
};
