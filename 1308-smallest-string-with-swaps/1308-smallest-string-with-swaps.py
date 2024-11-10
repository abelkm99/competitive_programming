class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:

        n = len(s)

        DSU = [-1] * (n)

        def find(i: int):
            if DSU[i] < 0:
                return i
            DSU[i] = find(DSU[i])
            return DSU[i]
        
        
        def join(i: int, j: int):
            i, j = find(i), find(j)
            if i == j:
                return
            if DSU[i] > DSU[j]:
                i, j = j, i
            DSU[i] += DSU[j]
            DSU[j] = i
        
        for u, v in pairs:
            join(u, v)
        
        groups = defaultdict(list)

        for i in range(n):
            groups[find(i)].append(s[i])
        
        for g in groups.keys():
            groups[g] = sorted(groups[g], reverse = True)
        
        # print(groups)

        # reverse sorted

        ans = [' '] * n
        for i in range(n):
            ans[i] = groups[find(i)].pop()
        
        return "".join(ans)