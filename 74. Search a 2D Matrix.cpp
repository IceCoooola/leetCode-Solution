class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m-1;
        while (up <= down) {
            int mid = (up + down) / 2;
            if (target > matrix[mid][n-1]) {
                up = mid + 1;
            } else if (target < matrix[mid][0]) {
                down = mid - 1;
            } else {
                // target between matrix[mid][0 - n-1]
                int left = 0;
                int right = n-1;
                while (left <= right) {
                    int m = (left + right) / 2;
                    if (target > matrix[mid][m]) {
                        left = m+1;
                    }else if (target < matrix[mid][m]){
                        right = m-1;
                    }else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
