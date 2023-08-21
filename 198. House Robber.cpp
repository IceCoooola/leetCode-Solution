class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> rb(sz + 1);
        vector<int> Norb(sz + 1);
        for(int i = 1; i <= sz; i++)
        {
            rb[i] = Norb[i-1] + nums[i-1];
            Norb[i] = max(Norb[i-1], rb[i-1]);
        }
        return max(Norb[sz], rb[sz]);
    }
};
