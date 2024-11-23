from collections import defaultdict
import bisect
class TimeMap:

    def __init__(self):
        self.store: dict[list[tuple[int,int]]] = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append((timestamp, value))
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        arr = self.store[key]
        idx = bisect.bisect_left(arr, (timestamp, ""))
        if idx == len(arr):
            return arr[-1][1]
            
        if arr[idx][0] == timestamp:
            return arr[idx][1]
        idx -= 1
        if idx < 0:
            return ""
        return arr[idx][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)