class Solution:

    def ans(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        ans = 0
        for i in range(len(nums)):
            dp[i] = max((dp[i - 2] if i - 2 >= 0 else 0 )+ nums[i], dp[i - 1] if i - 1 >= 0 else 0)
            ans = max(ans, dp[i])
        return ans
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(self.ans(nums[:-1]), self.ans(nums[1:]))
        