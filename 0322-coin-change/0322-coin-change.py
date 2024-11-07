class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf") for _ in range(amount + 1)]
        dp[0] = 0
        # if don't pick this one
        for rem in range(amount + 1):
            for coin in coins:
                if rem - coin >= 0:
                    dp[rem] = min(dp[rem], dp[rem - coin] + 1)

        ans = dp[amount]
        return ans if ans != float("inf") else -1
