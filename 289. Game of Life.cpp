class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> change(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = getAliveCells(board, i, j);
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        change[i][j] = true;
                    }
                } else {
                    if (live == 3) {
                        change[i][j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (change[i][j]) board[i][j] = 1 - board[i][j];
            }
        }
    }

    int getAliveCells(vector<vector<int>>& board, int x, int y) {
        int ret = 0;
        int n = board[0].size() < y + 2? board[0].size() : y + 2;
        int m = board.size() < x + 2? board.size(): x + 2;
        for (int i = max(0, x - 1); i < m; i++) {
            for (int j = max(0, y - 1); j < n; j++) {
                ret += board[i][j];
            }
        }
        ret -= board[x][y];
        return ret;
    }
};
