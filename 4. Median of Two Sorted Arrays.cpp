class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int cur1 = 0, cur2 = 0;
        while(cur1 < nums1.size() && cur2 < nums2.size())
        {
            if(nums1[cur1] < nums2[cur2])
            {
                num.push_back(nums1[cur1++]);
            }
            else
            {
                num.push_back(nums2[cur2++]);
            }
        }
        while(cur1 != nums1.size())
        {
                num.push_back(nums1[cur1++]);
        }
        while(cur2 != nums2.size())
        {
                num.push_back(nums2[cur2++]);
        }
        if(num.size() % 2 == 0)
        {
            return ((double)num[num.size() / 2] + (double)num[num.size()/2 - 1])/2;
        }
        else
        {
            return (double)num[num.size() / 2];
        }
        return -1;
    }
};
