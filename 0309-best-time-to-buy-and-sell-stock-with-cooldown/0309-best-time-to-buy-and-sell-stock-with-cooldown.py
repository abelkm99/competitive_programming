class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # class do this and do that how do i use.
        @cache
        def solve(idx: int, state: int) -> int:
            if idx >= len(prices):
                return 0

            # i have the option to not do shit on this one i guess
            cool_down = solve(idx + 1, state) # cool down by one

            if state == 0:
                return max(solve(idx + 1, 1) - prices[idx], cool_down)

            return max(solve(idx + 2, 0) + prices[idx], cool_down)
        
        return solve(0, 0)