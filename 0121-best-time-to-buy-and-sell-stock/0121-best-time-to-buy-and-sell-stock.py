class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn = float("inf")
        ans = 0
        for price in prices:
            ans = max(ans, price - mn)
            mn = min(mn, price)
        return ans