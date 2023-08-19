class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int left = 0;
        int right = 1;
        while(right < nums.size())
        {
            if(nums[right] == nums[left])
            {
                right++;
            }
            else{
                nums[++left] = nums[right++];
            }
        }
        return left+1;
    }
};

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0;
//         int j = 1;
//         while(j < nums.size())
//         {
//             if(nums[i] != nums[j])
//             {
//                 nums[i+1] = nums[j];
//                 i++;
//                 j++;
//             }
//             else
//             {
//                 j++;
//             }
//         }
//         return i+1;
//     }
// };
