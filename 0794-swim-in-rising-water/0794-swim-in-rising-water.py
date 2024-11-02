class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visited = [[-1 for _ in range(n)] for _ in range(n)]

        def is_valid(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < n and visited[i][j] == -1

        heap = []
        heappush(heap, (grid[0][0], 0, 0))

        while heap:
            cost, i, j = heappop(heap)

            if visited[i][j] != -1:
                continue

            visited[i][j] = cost

            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                x, y = i + dx, j + dy

                if is_valid(x, y):
                    heappush(heap, (max(grid[x][y], cost) ,x , y))
        
        return visited[n-1][n-1]