import bisect
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        for i, num in enumerate(nums):
            idx = bisect.bisect_left(dp, num)
            if idx == len(dp):
                dp.append(num)
            else:
                dp[idx] = num
        return len(dp)

