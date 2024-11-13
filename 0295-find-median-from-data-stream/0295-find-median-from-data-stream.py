
class MedianFinder:

    def __init__(self):
        self.heaps = [], []
        

    def addNum(self, num: int) -> None:
        smaller, larger = self.heaps

        heappush(smaller, -1 * num)
        heappush(larger, -1 * heappop(smaller))


        if len(larger) - len(smaller) > 1:
            heappush(smaller, -1 * heappop(larger))
        
        # print("add ",smaller, larger)

    def findMedian(self) -> float:
        smaller, larger = self.heaps

        # print(larger, smaller)

        if len(larger) > len(smaller):
            return larger[0]

        return (larger[0] + (smaller[0] * -1)) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()