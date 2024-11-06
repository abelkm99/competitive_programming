class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        

        @cache
        def solve(idx:int, rem: int):
            if rem == 0:
                return 0
            if rem < 0 or idx == len(coins):
                return float("inf")
            return min(solve(idx + 1, rem), solve(idx, rem - coins[idx]) + 1)
        
        ans = solve(0, amount)
        return ans if ans != float("inf") else -1
