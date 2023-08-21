class Solution {
public:
    int massage(vector<int>& nums) {
        int sz = nums.size();
        vector<int> choose(sz+1);
        vector<int> NoChoose(sz+1);
        for(int i = 1; i <= sz; i++)
        {
            choose[i] = nums[i-1] + NoChoose[i-1];
            NoChoose[i] = max(choose[i-1], NoChoose[i-1]);
        }
        return max(choose[sz], NoChoose[sz]);
    }
};

// class Solution {
// public:
//     int massage(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         int sz = nums.size();
//         vector<int> choose(sz);
//         vector<int> NoChoose(sz);
//         choose[0] = nums[0];
//         for(int i = 1; i < sz; i++)
//         {
//             choose[i] = nums[i] + NoChoose[i-1];
//             NoChoose[i] = max(choose[i-1], NoChoose[i-1]);
//         }
//         return max(choose[sz-1], NoChoose[sz-1]);
//     }
// };
