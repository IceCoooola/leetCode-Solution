class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> len(sz,1), count(sz,1);
        int maxLen = 1;
        int maxCount = 1;
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(len[j] + 1 == len[i])
                    {
                        count[i] += count[j];
                    }
                    else if(len[j] + 1 > len[i])
                    {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
            if(maxLen == len[i])
                maxCount += count[i];
            else if(maxLen < len[i])
                maxLen = len[i], maxCount = count[i];
        }
        return maxCount;
    }
};
