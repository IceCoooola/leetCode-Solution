class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        set<vector<int>> st;
        for(int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                int left = j + 1;
                int right = n - 1;
                long long new_target = target;
                new_target -= nums[i];
                new_target -= nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] == new_target) {
                        st.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    }
                    else if (nums[left] + nums[right] < new_target) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }
        for (auto e: st) ret.push_back(e);
        return ret;
    }
};
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         vector<vector<int>> ret;
//         set<vector<int>> st;
//         for (int a = 0; a < n-3; ++a) {
//             for (int b = a + 1; b < n-2; ++b) {
//                 for (int c = b + 1; c < n-1; ++c) {
//                     for (int d = c + 1; d < n; ++d) {
//                         long long sum = nums[a];
//                         sum += + nums[b];
//                         sum += nums[c];
//                         sum += nums[d];
//                         if (sum == target) {
//                             st.insert({nums[a], nums[b], nums[c], nums[d]});
//                         } 
//                     }
//                 }
//             }
//         }
//         for (auto e : st) {
//             ret.push_back(e);
//         }
//         return ret;
//     }
// };
