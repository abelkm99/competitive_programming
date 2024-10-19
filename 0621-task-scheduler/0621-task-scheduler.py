from collections import deque, Counter
from heapq import heapify, heappush, heappop
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap = [-1 * x for x in Counter(tasks).values()]
        heapify(heap)
        dq = deque()
        print(heap, dq)

        time = 0
        while heap or dq:
            while dq and time > dq[0][1]:
                heappush(heap, dq.popleft()[0])
                pass
            if heap:
                rem = heappop(heap)
                rem += 1
                if rem < 0:
                    dq.append((rem, time + n))
            time += 1

        return time
