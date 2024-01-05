class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    count += 1;
                    search(grid, i, j);
                }
            }
        }
        return count;
    }

    void search(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = 9;
        if (x - 1 >= 0 && grid[x-1][y] == '1') search(grid, x-1, y);
        if (x + 1 < grid.size() && grid[x+1][y] == '1') search(grid, x+1, y);
        if (y - 1 >= 0 && grid[x][y-1] == '1') search(grid, x, y-1);
        if (y + 1 < grid[0].size() && grid[x][y+1] == '1') search(grid, x, y+1);
    }
};
