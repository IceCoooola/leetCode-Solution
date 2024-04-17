class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_set = set()
        col_set = set()
        cube_set = set()
        for i in range(9):
            
            for j in range(9):
                if board[i][j] != '.':
                    t_row = "row " + str(i) + " " + board[i][j]
                    t_col = "col " + str(j) + " " + board[i][j]
                    t_square = "cube " + str(i // 3) + str(j // 3) + " " + board[i][j]
                    # print(t_row)
                    # print(t_col)
                    # print(t_square)
                    if t_row in row_set or t_col in col_set or t_square in cube_set:
                        return False
                    row_set.add(t_row)
                    col_set.add(t_col)
                    cube_set.add(t_square)
        return True
