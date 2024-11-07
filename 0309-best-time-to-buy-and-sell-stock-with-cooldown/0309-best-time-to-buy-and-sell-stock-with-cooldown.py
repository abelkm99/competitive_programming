class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # class do this and do that how do i use.
        @cache
        def solve(idx: int, state: int) -> int:
            if idx == len(prices):
                return 0
            if state == 0:
                return max(solve(idx + 1, 1) - prices[idx], solve(idx + 1, state))
            if state == 1:
                return max(solve(idx + 1, 2) + prices[idx], solve(idx + 1, state))
            return solve(idx + 1, 0)
        
        return solve(0, 0)