class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        
        prefix = [0] * 1001

        for c, l, r in trips:
            prefix[l] += c
            prefix[r] -= c
        for i in range(1, len(prefix)):
            prefix[i] += prefix[i - 1]
            if prefix[i] > capacity:
                return False
        return prefix[0] <= capacity
