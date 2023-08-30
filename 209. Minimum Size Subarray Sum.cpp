class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size();
        int right = 0;
        int minlen = 0;
        int sum = 0;
        int left = 0;
        for(int i = 0; i < sz; i++)
        {
            sum += nums[i];
            right++;
            while(sum >= target)
            {
                if(minlen != 0)
                    minlen = min(minlen, right - left);
                else
                    minlen = right - left;
                sum -= nums[left++];
            }
        }
        return minlen;
    }
};
