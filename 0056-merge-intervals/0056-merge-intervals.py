class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans: list[list[int]] = []

        intervals.sort()
        print(intervals)

        for s, e in intervals:
            if not ans:
                ans.append([s, e])
                continue
            if s <= ans[-1][1]:
                ans[-1][1] = max(ans[-1][1], e)
                continue
            ans.append([s, e])
        return ans