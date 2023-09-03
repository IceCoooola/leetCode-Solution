class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int left = 0;
        int right = sz - 1;
        int ret = 0;
        while(right > left)
        {
            ret = max(ret, min(height[right], height[left]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ret;
    }
};
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int i = 0, j = height.size() - 1;
//         int Area = min(height[i], height[j]) * (j - i);
//         while(j > i)
//         {
//             if(height[i] < height[j])
//             {
//                 i++;
//             }
//             else
//             {
//                 j--;
//             }
//             if(min(height[i], height[j]) * (j - i) > Area)
//                 Area = min(height[i], height[j]) * (j - i);
//         }
//         return Area;
//     }
// };
