class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1 for _ in range(len(nums))]
        ans = 0
        for i, num in enumerate(nums):
            j = i - 1
            while j >= 0:
                if nums[j] < num:
                    dp[i] = max(dp[i], dp[j] + 1)
                j -= 1
            ans = max(ans, dp[i])
        return ans

