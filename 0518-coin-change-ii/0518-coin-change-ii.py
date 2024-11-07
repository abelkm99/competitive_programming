class Solution:
    def change(self, amount: int, coins: List[int]) -> int:

        @cache
        def solve(amount: int, idx: int):
            if amount == 0:
                return 1
            if amount < 0 or idx < 0:
                return 0
            
            return solve(amount - coins[idx], idx) + solve(amount, idx - 1)
        return solve(amount, len(coins) - 1)
