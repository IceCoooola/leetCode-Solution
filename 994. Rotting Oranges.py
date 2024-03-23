from collections import deque 
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        dq = collections.deque()
        num_fresh_orange = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    num_fresh_orange += 1
                elif grid[i][j] == 2:
                    dq.append((i, j))
        cur_num = len(dq)
        timestep = 0
        while len(dq) > 0:
            i, j = dq.popleft()
            if i - 1 >= 0 and grid[i-1][j] == 1:
                grid[i-1][j] = 2
                dq.append((i-1, j))
                num_fresh_orange -= 1
            if j - 1 >= 0 and grid[i][j-1] == 1:
                grid[i][j-1] = 2
                dq.append((i, j-1))
                num_fresh_orange -= 1
            if i + 1 < m and grid[i+1][j] == 1:
                grid[i+1][j] = 2
                dq.append((i+1, j))
                num_fresh_orange -= 1
            if j + 1 < n and grid[i][j+1] == 1:
                grid[i][j+1] = 2
                dq.append((i, j+1))
                num_fresh_orange -= 1
            cur_num -= 1
            if cur_num == 0:
                cur_num = len(dq)
                timestep += 1
        if num_fresh_orange > 0:
            return -1
        if timestep > 0:
            return timestep - 1
        return 0
