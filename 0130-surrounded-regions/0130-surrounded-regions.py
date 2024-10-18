class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n, m = len(board), len(board[0])

        def valid(i: int, j: int) -> bool:
            return i >= 0 and i < n and j >= 0 and j < m
        

        def DFS(i: int, j:int, pos: list[tuple[int,int]]) -> bool:
            if not valid(i, j):
                return True
            if board[i][j] != 'O':
                return False
            board[i][j] = '-1'
            pos.append((i, j))
            ans = False
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                x, y = dx + i, dy + j
                ans = DFS(x, y, pos) or ans
            return ans
        
        for i in range(1,n-1):
            for j in range(1,m-1):
                if board[i][j] == 'O':
                    pos: list[tuple[int,int]] = []
                    res = DFS(i, j, pos)
                    for x, y in pos:
                        board[x][y] = '#' if res else 'X'

        for i in range(n):
            for j in range(m):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                        
