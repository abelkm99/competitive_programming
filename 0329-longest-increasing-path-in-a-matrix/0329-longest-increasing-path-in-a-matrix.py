class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        in_node = [[0 for _ in range(m)] for _ in range(n)]

        def in_bound(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < m

        
        for i in range(n):
            for j in range(m):
                for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    x, y = dx + i, dy + j
                    if in_bound(x, y) and matrix[i][j] < matrix[x][y]:
                        in_node[x][y] += 1

        dq = deque()

        ans = 1

        for i in range(n):
            for j in range(m):
                if not in_node[i][j]:
                    dq.append((i, j, 1))
        
        print(dq)
        while dq:
            i, j, c = dq.popleft()
            ans = max(ans, c)
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                x, y = dx + i, dy + j
                if in_bound(x, y) and matrix[i][j] < matrix[x][y]:
                    in_node[x][y] -= 1
                    if in_node[x][y] == 0:
                        dq.append((x, y, c + 1))
        return ans