class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def can(k: int) -> bool:
            tmp = 0
            for x in piles:
                tmp += ((x + k - 1) // k)
            return tmp <= h
        l, r = 1, 100000000000
        ans = r
        while l <= r:
            k = (r - l) // 2 + l
            if can(k):
                ans = k
                r = k - 1
            else:
                l = k + 1

        return ans

