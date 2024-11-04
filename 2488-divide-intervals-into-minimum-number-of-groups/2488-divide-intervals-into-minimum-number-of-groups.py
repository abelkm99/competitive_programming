class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        ans = 0
        intervals.sort()
        heap = []
        for s, e in intervals:
            while heap and heap[0] < s:
                heappop(heap)
            heappush(heap, e)
            ans = max(ans, len(heap))

        return ans