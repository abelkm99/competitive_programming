class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def can(k: int) -> bool:
            return sum([(x + k - 1) // k for x in piles]) <= h
        l, r = 1, 10000000000
        ans = r
        while l <= r:
            k = (l + r) // 2
            if can(k):
                ans = k
                r = k - 1
            else:
                l = k + 1

        return ans

