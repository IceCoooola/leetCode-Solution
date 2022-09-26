class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int i = 0;
        for(i; i < nums.size();i++)
        {
            sum+=i;
            sum-=nums[i];
        }
        sum+=i;
        return sum;
    }
};
