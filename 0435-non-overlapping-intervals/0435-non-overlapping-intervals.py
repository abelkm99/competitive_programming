class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        cnt = 0
        ans = []
        intervals.sort()



        # i would assume
        for s, e in intervals:
            if not ans:
                ans.append([s, e])
                continue
            if s < ans[-1][1]:
                # select the minimum distance
                ans[-1][1] = min(ans[-1][1], e)
                cnt += 1
                continue
            ans.append([s, e])
        
        return cnt