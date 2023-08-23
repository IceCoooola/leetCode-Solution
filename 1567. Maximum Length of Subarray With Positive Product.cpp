class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int sz = nums.size();
        vector<int> pos(sz);
        vector<int> neg(sz);
        int maxLen = 0;
        if(nums[0] > 0)
        {    
            pos[0] = 1;
            maxLen = 1;
        }
        else if(nums[0] < 0)
            neg[0] = 1;
        for(int i = 1; i < sz; i++)
        {
            if(nums[i] < 0)
            {   
                pos[i] = (neg[i-1] == 0 ? 0 : neg[i-1] + 1);
                neg[i] = pos[i-1] + 1;
            }
            else if(nums[i] > 0)
            {
                pos[i] = pos[i-1] + 1;
                neg[i] = (neg[i-1] == 0? 0 : neg[i-1] + 1);
            }
            if(pos[i] > maxLen)
                maxLen = pos[i];
        }
        return maxLen;
    }
};
// class Solution {
// public:
//     int getMaxLen(vector<int>& nums) {
//         int sz = nums.size();
//         vector<int> pos(sz);
//         vector<int> neg(sz);
//         int maxLen = 0;
//         if(nums[0] > 0)
//         {    
//             pos[0] = 1;
//             maxLen = 1;
//         }
//         else if(nums[0] < 0)
//             neg[0] = 1;
//         for(int i = 1; i < sz; i++)
//         {
//             if(nums[i] < 0)
//             {   
//                 pos[i] = (neg[i-1] == 0 ? 0 : neg[i-1] + 1);
//                 neg[i] = pos[i-1] + 1;
//             }
//             else if(nums[i] > 0)
//             {
//                 pos[i] = pos[i-1] + 1;
//                 neg[i] = (neg[i-1] == 0? 0 : neg[i-1] + 1);
//             }
//             else
//             {
//                 pos[i] = neg[i] = 0;
//             }
//             if(pos[i] > maxLen)
//                 maxLen = pos[i];
//         }
//         return maxLen;
//     }
// };
