class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        G: dict[int,list[tuple[int,int]]] = defaultdict(list)
        for u, v, cost in flights:
            G[u].append((v, cost))
        
        distance = [float('inf') for _ in range(n)]
        distance[src] = 0

        for _ in range(k+1):
            ans = [float('inf') for _ in range(n)]
            for u in range(n):
                for v, c in G[u]:
                    ans[v] = min(ans[v], distance[u] + c)
            for i in range(n):
                distance[i] = min(distance[i], ans[i])
        
        return distance[dst] if distance[dst] < float("inf") else -1