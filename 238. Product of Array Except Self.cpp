class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> productbefore(sz, 1);
        vector<int> productafter(sz, 1);
        vector<int> ret(sz);
        for(int i = 1; i < sz; i++)
        {
            productbefore[i] = productbefore[i-1] * nums[i-1];
            productafter[sz-i-1] = productafter[sz-i] * nums[sz-i];
        }
        for(int i = 0; i < sz; i++)
        {
            ret[i] = productafter[i] * productbefore[i];
        }
        return ret;
    }
};
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int product = 1;
//         int count = 0;
//         vector<int> ret;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == 0)
//             {
//                 count++;
//                 if(count >= 2)
//                 {
//                     ret.assign(nums.size(),0);
//                     return ret;
//                 }
//             }
//             else
//             {
//                 product *= nums[i];
//             }
//         }
//         if(count == 1)
//         {
//             for(int i = 0; i < nums.size(); i++)
//             {
//                 if(nums[i] != 0)
//                 {
//                     ret.push_back(0);
//                 }
//                 else
//                 {
//                     ret.push_back(product);
//                 }
//             }
//         }
//         else
//         {
//             for(int i = 0; i < nums.size(); i++)
//             {
//                 ret.push_back(product / nums[i]);
//             }
//         }
//         return ret;
//     }
// };
