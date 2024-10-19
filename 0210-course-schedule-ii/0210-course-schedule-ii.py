from collections import deque
class Solution:
    def findOrder(self, n: int, edges: List[List[int]]) -> List[int]:
        G = [[] for _ in range(n)]
        in_nodes = [0] * n

        for v, u in edges:
            G[u].append(v)
            in_nodes[v] += 1
        
        dq = deque()
        
        for i, cnt in enumerate(in_nodes):
            if cnt == 0:
                dq.append(i)
        
        ans: list[int] = []
        while dq:
            u = dq.popleft()
            ans.append(u)
            for v in G[u]:
                in_nodes[v] -= 1
                if in_nodes[v] == 0:
                    dq.append(v)
                    continue
                if in_nodes[v] < 0:
                    return []
                    
        return ans