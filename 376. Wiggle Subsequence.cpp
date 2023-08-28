class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        vector<int> maxIncrease(sz, 1);
        vector<int> maxDecrease(sz, 1);
        int ret = 1;
        for(int i = 1; i < sz; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[j] < nums[i])
                    maxIncrease[i] = max(maxDecrease[j] + 1, maxIncrease[i]);
                if(nums[j] > nums[i])
                    maxDecrease[i] = max(maxIncrease[j] + 1, maxDecrease[i]);
            }
            ret = max(ret, max(maxDecrease[i], maxIncrease[i]));
        }
        return ret;
    }
};
