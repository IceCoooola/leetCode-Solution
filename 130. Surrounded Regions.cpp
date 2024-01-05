class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            if(board[i][0] == 'O') {
                flip(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                flip(board, i, n-1);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                flip(board, 0, j);
            }
            if (board[m-1][j] == 'O') {
                flip(board, m-1, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void flip(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'T';
        if (x-1 >=0 && board[x-1][y] == 'O') flip(board, x-1, y);
        if (y-1 >=0 && board[x][y-1] == 'O') flip(board, x, y-1);
        if (x+1 < board.size() && board[x+1][y] == 'O') flip(board, x+1, y);
        if (y+1 < board[0].size() && board[x][y+1] == 'O') flip(board, x, y+1);
    }
};
