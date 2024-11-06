class Solution:
    def rob(self, nums: List[int]) -> int:


        @lru_cache
        def dp(idx):
            if idx >= len(nums):
                return 0
            return max(dp(idx + 2) + nums[idx], dp(idx + 1))
        
        return dp(0)