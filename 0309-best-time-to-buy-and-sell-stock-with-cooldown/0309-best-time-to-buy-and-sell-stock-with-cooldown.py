class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # class do this and do that how do i use.
        @cache
        def solve(idx: int, prev: int ,state: int) -> int:
            # if state 0 -> means i can buy or not (i cant sell)
            # if state 1 -> i've bought i can sell or not
            # if state 2 ->  means i am cooling of so i can't do shit
            # ballance
            if idx == len(prices):
                # if it's finished return the previous bought data
                return -1 * prev
            # the state matters a lot
            if state == 0:
                # buy the current or don't buy
                return max(solve(idx + 1, prices[idx], 1), solve(idx + 1, prev, state))
            if state == 1:
                # means i can seel it or don't sell it
                # if i sell it change the state to cool off period
                return max(solve(idx + 1, 0, 2) + prices[idx] - prev, solve(idx + 1, prev, state))
            # means the state is 2 with an option to buy a stock
            return solve(idx + 1, 0, 0)
        
        return solve(0, 0, 0)