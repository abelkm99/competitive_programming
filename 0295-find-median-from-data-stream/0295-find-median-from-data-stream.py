from heapq import heappush, heappop
class MedianFinder:

    def __init__(self):
        self.mn = []
        self.mx = []
        

    def addNum(self, num: int) -> None:
        heappush(self.mx, -1 * num)

        # as long as the values on the max heap is minimum than the smallest value on the # mn heap

        # print(self.mn, self.mx)
        while self.mx and self.mn and -1 * self.mx[0] > self.mn[0]:
            heappush(self.mn, -1 * heappop(self.mx))

        while abs(len(self.mn) - len(self.mx)) > 1:
            if len(self.mn) > len(self.mx):
                heappush(self.mx, -1 * heappop(self.mn))
            else:
                heappush(self.mn, -1 * heappop(self.mx))


    def findMedian(self) -> float:
        # print("ans",self.mn, self.mx)


        if (len(self.mn) + len(self.mx)) & 1:
            if len(self.mn) > len(self.mx):
                return self.mn[0]
            else:
                return -1 * self.mx[0]
        
        return (-1 * self.mx[0] + self.mn[0]) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()