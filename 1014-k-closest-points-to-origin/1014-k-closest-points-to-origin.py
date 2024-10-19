class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        heap: tuple[int,int,int] = []
        for x, y in points:
            heappush(heap, (-1*((x**2 + y**2)**0.5) ,x , y))
            if len(heap) > k:
                heappop(heap)
        ans = []
        while heap:
            d, x, y = heappop(heap)
            ans.append([x, y])
        return ans[::-1]
            