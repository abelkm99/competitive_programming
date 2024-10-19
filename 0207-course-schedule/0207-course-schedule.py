class Solution:
    def canFinish(self, n: int, edges: List[List[int]]) -> bool:
        G = [[] for _ in range(n)]
        visited = [0] * n
        local = [0] * n
        can = True

        for v, u in edges:
            G[u].append(v)
        
        def dfs(u):
            nonlocal can
            if visited[u]:
                return
            if local[u]:
                can = False
                return
            local[u] = 1
            for v in G[u]:
                dfs(v)
            local[u] = 0
            visited[u] = 1

        for i in range(n):
            dfs(i)

        return can