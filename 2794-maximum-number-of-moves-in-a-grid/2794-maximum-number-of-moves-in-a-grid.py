class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]

        for i in range(n):
            dp[i][m - 1] = 0
        
        def in_bound(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < m
        
        ans = 0
        for c in range(m - 2, -1, -1):
            for r in range(n):
                for x, y in [(-1, 1), (0, 1), (1, 1)]:
                    dx, dy = r + x, c + y
                    if in_bound(dx, dy) and grid[r][c] < grid[dx][dy]:
                        dp[r][c] = max(dp[r][c], dp[dx][dy] + 1)
                        if c == 0:
                            ans = max(ans, dp[r][c])
        for i in range(n):
            print(dp[i])
        return ans