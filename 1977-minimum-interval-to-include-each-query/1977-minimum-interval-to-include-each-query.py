class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        ans: list[int] = []
        memo = {}
        p = 0
        heap = []
        for i, q in enumerate(sorted(queries)):
            if q in memo:
                continue
            while p < len(intervals) and not intervals[p][0] > q:
                heappush(heap, (intervals[p][1] - intervals[p][0] + 1, intervals[p][0], intervals[p][1] ))
                # if q >= intervals[l][0] and q <= intervals[l][1]:
                p += 1
            # print("for ", q, heap)
            while heap:
                dst, l, r = heap[0]
                if q >= l and q <= r:
                    break
                else:
                    heappop(heap)
            memo[q] = heap[0][0] if heap else -1

        print(memo)
        print(queries)
        for q in queries:
            ans.append(memo[q])
        
        return ans