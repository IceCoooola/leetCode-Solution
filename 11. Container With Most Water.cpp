class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int Area = min(height[i], height[j]) * (j - i);
        while(j > i)
        {
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            if(min(height[i], height[j]) * (j - i) > Area)
                Area = min(height[i], height[j]) * (j - i);
        }
        return Area;
    }
};
