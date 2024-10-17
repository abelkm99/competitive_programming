class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        def in_bound(i: int, j: int):
            return i >= 0 and i < n and j >= 0 and j < m
        
        def DFS(i: int, j: int):
            if not in_bound(i, j) or grid[i][j] != 1:
                return 0

            grid[i][j] = -1
            ans = 1
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                ans += DFS(i + dx, j + dy)
            return ans
        
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans = max(ans, DFS(i,j))
        return ans