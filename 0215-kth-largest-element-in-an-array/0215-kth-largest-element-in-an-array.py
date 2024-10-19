class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # to solve it with
        heap = []
        for num in nums:
            heappush(heap, num)
            if len(heap) > k:
                heappop(heap)
        return heap[0]