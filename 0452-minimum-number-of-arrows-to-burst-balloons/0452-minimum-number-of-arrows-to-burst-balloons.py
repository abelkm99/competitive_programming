class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        cnt = 1
        l, r = float("-inf"), float("inf")
        for s, e in points:
            if (s <= r and s >= l) or (e <= r and e >= l):
                l = max(l, s)
                r = min(r, e)
            else:
                cnt += 1
                l, r = s, e
        return cnt 
