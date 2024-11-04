class Solution:
    def insert(self, intervals: List[List[int]], ni: List[int]) -> List[List[int]]:

        # add it there 
        new_arr = []
        added = False
        for s, e in intervals:
            if not added and ni[0] <= s:
                added = True
                new_arr.append(ni)
            new_arr.append([s, e])
            
        if not added:
            new_arr.append(ni)

        # merge the interval
        ans = []
        for s, e in new_arr:
            if not ans:
                ans.append([s, e])
                continue

            if s <= ans[-1][1]:
                ans[-1][1] = max(e, ans[-1][1])
                continue
            ans.append([s, e])

        return ans