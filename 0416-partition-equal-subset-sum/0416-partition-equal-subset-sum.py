class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        total = sum(nums)
        if total & 1:
            return False
        # 
        target = total // 2
        dp = [0] * (target + 1)
        dp[0] = 1

        for c in nums:
            tmp = dp.copy()
            for i in range(target, c - 1, -1):
                dp[i] |= dp[i - c]

        return dp[target] == 1