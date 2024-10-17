from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dq = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    dq.append((i, j, 0))
        
        ans: int = 0

        def is_valid(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == 1

        while dq:
            i, j, c = dq.popleft()
            ans = max(ans, c)
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                x, y = i + dx, j + dy
                if is_valid(x, y):
                    grid[x][y] = 2
                    dq.append((x, y, c+1))

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        return ans