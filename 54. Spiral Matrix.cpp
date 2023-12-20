class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> ret;
        while (top <= bot && right >= left) {
            // 1 2 3 4
            for (int j = left; j <= right; j++) {
                ret.push_back(matrix[top][j]);
            }
            top++;
            for (int i = top; i <= bot; i++) {
                ret.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bot) {
                for (int j = right; j >= left; j--) {
                ret.push_back(matrix[bot][j]);
                }
                bot--;
            }
            if (left <= right) {
                for (int i = bot; i >= top; i--) {
                    ret.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ret;
    }
};
