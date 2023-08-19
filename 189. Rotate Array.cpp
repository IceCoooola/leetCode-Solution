class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%= nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(),nums.end());
    }
};
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k %= nums.size();
//         vector<int> tmp(nums);
//         tmp.insert(tmp.end(), nums.begin(), nums.end());
//         int t = nums.size() - k;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             nums[i] = tmp[i+t];
//         }
//     }
// };
