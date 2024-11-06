class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        # by the time i am there i should have gotten the max so far
        ans = 0
        for i in range(len(nums)):
            dp[i] = max((dp[i - 2] if i - 2 >= 0 else 0 )+ nums[i], dp[i - 1] if i - 1 >= 0 else 0)
            ans = max(ans, dp[i])
        return ans