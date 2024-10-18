from collections import deque
class Solution:
    def BFS(self, grid: List[List[int]], pos: list[tuple[int,int]]) -> list[list[int]]:
        n, m = len(grid), len(grid[0])
        visited = [[0 for _ in range(m)] for _ in range(n)]
        v = [[0] * m] * n

        def valid(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < m



        dq = deque(pos)
        while dq:
            i, j = dq.pop()
            if visited[i][j]: # continue if it is visited
                continue
            visited[i][j] = 1
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                x, y = i + dx, j + dy
                if valid(x, y) and grid[x][y] >= grid[i][j]:
                    dq.append((x, y))
        return visited

    def pacificAtlantic(self, grid: List[List[int]]) -> List[List[int]]:
        # for pacific ocean
        n, m = len(grid), len(grid[0])

        pacifics = []
        for j in range(m):
            pacifics.append((0, j))
        for i in range(n):
            pacifics.append((i, 0))

        atlantics = []

        for j in range(m):
            atlantics.append((n - 1, j))
        for i in range(n):
            atlantics.append((i, m - 1))

        v1 = self.BFS(grid, pacifics)
        v2 = self.BFS(grid, atlantics)

        ans: list[list[int]] = []
        for i in range(n):
            for j in range(m):
                if v1[i][j] and v2[i][j]:
                    ans.append([i, j])
        return ans