class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.solver(board, 0, 0)

    def solver(self, board: List[List[str]], i, j) -> bool:
        if j == 9: 
            i += 1
            j = 0
        if i == 9:
            return True
        if board[i][j] != '.': 
            return self.solver(board, i, j + 1)

        for num in range(1, 10):
            if self.is_valid(board, i, j, str(num)): 
                board[i][j] = str(num)
                if self.solver(board, i, j + 1):
                    return True
                board[i][j] = '.'
        return False  

    def is_valid(self, board: List[List[str]], row, col, num) -> bool:
        block_row = (row // 3) * 3
        block_col = (col // 3) * 3
        for k in range(9): 
            if board[row][k] == num or board[k][col] == num:
                return False
            if board[block_row + k // 3][block_col + k % 3] == num:
                return False
        return True
