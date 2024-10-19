class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        DSU = [i for i in range(len(edges) + 1)]

        def find(i: int):
            if DSU[i] == i:
                return i
            DSU[i] = find(DSU[i])
            return DSU[i]
        
        def join(i: int, j: int) -> bool:
            i, j = find(i),  find(j)
            if i == j:
                return True
            DSU[j] = i
            return False

        ans = None

        for i, j in edges:
            if join(i, j):
                ans = [i, j]
        return ans