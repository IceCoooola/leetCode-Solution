class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //swap left and right
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-i-1; j++) {
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
    }
};
