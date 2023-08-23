class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        vector<int> minDp(sz+1);
        vector<int> maxDp(sz+1);
        minDp[0] = maxDp[0] = 1;
        int maxProduct = INT_MIN;
        for(int i = 1; i <= sz; i++)
        {
            int x = nums[i-1];
            int y = nums[i-1] * minDp[i-1];
            int z = nums[i-1] * maxDp[i-1];
            minDp[i] = min(min(x, y),z);
            maxDp[i] = max(max(x, y),z);
            if(maxDp[i] > maxProduct)
                maxProduct = maxDp[i];
        }
        return maxProduct;
    }
};
