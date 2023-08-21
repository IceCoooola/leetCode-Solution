class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> st = new HashSet<>();
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                if (!st.add("Row " + i + board[i][j]))
                    return false;
                if(!st.add("Col " + j + board[i][j]))
                    return false;
                if(!st.add("Row" + i / 3 + " Col " + j / 3 + board[i][j]))
                    return false;
                }
            }
        }
        return true;
    }
}
