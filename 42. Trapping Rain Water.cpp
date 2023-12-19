class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = -1, rightMax = -1;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            water += rightMax > leftMax? leftMax - height[left++] : rightMax - height[right--];
        }
        return water;
    }
};
