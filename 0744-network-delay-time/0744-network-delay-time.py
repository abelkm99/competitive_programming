from heapq import heappush, heappop
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        visited = [float("inf")] * (n + 1)
        G = defaultdict(list[tuple[int,int]])
        for u, v, w in times:
            G[u].append((v, w))

        heap = []
        heappush(heap, (0, k))

        while heap:
            cost, u = heappop(heap)
            if visited[u] <= cost:
                continue
            visited[u] = cost

            for v, c in G[u]:
                heappush(heap, (cost + c, v))


        ans = max(visited[1:])

        return -1 if ans == float("inf") else ans