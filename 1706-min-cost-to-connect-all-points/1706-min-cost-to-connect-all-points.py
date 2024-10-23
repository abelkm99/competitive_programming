from heapq import heappush, heappop
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)

        DSU = [-1] * n
        def find(i: int) -> int:
            if DSU[i] < 0:
                return i
            DSU[i] = find(DSU[i])
            return DSU[i]
        
        
        def join(i: int, j: int) -> bool:
            i, j = find(i), find(j)
            if i == j:
                return False
            if DSU[i] < DSU[j]:
                i, j = j, i
            DSU[i] += DSU[j]
            DSU[j] = i
            return True


        heap = []
        for i in range(len(points)):
            for j in range(i, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                heappush(heap,( abs(x1 - x2) + abs(y1 - y2) , i, j))
        
        cost = 0

        while heap:
            tmp, u, v = heappop(heap)
            # print(u, v)
            if join(u, v):
                cost += tmp

        return cost
        