class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> tmp(nums);
        tmp.insert(tmp.end(), nums.begin(), nums.end());
        int t = nums.size() - k;
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = tmp[i+t];
        }
    }
};
