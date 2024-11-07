class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [[float("inf") for _ in range(len(coins))] for _ in range(amount + 1)]
        # if don't pick this one
        for rem in range(amount + 1):
            for idx in range(len(coins)):
                if rem == 0:
                    dp[rem][idx] = 0
                    continue
                
                case_1 = dp[rem][idx - 1] if idx - 1 >= 0 else float("inf")
                case_2 = dp[rem - coins[idx]][idx] + 1 if rem -coins[idx] >= 0 else float("inf")

                dp[rem][idx] = min(case_1, case_2)

        ans = dp[amount][len(coins) - 1]
        return ans if ans != float("inf") else -1
