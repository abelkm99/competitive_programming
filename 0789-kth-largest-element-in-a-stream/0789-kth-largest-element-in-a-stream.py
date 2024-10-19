from heapq import heappush, heappop, heapify, heappushpop

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.max_heap = [x for x in nums]
        self.k = k

        heapify(self.max_heap)
        while len(self.max_heap) > k:
            heappop(self.max_heap)
            
    def add(self, val: int) -> int:
        heappush(self.max_heap, val)
        while len(self.max_heap) > self.k:
            heappop(self.max_heap)
        return self.max_heap[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)