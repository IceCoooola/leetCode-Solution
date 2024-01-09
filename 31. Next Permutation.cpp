class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = j - 1;
        while (i >= 0 && nums[i] >= nums[j]) {
            i -= 1;
            j -= 1;
        }
        if (i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int k = j;
        for (j; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) k = j;
        }
        swap(nums[i], nums[k]);
        reverse(nums.begin() + i + 1, nums.end());
// Find the largest index k such that a[k] < a[k + 1]. 
// If no such index exists, the permutation is the last permutation.
// Find the largest index l greater than k such that a[k] < a[l].
// Swap the value of a[k] with that of a[l].
// Reverse the sequence from a[k + 1] up to and including the final element a[n].
    }
};
