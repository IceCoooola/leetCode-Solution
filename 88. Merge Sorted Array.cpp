class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0)
        return;
    if(m == 0)
    {
        for(int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    int right1 = m - 1;
    int right2 = n - 1;
    int i = nums1.size() - 1;
    while(right2 >= 0 && right1 >= 0)
    {
        if(nums2[right2] >= nums1[right1])
        {
            nums1[i--] = nums2[right2--];
        }
        else
        {
            nums1[i--] = nums1[right1--];
        }
    }        
    while(right2>=0)
    {
        nums1[i--] = nums2[right2--];
    }
}
};
