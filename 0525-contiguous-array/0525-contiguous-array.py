class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        memo = {0: -1}
        sm = 0
        ans = 0
        for idx, num in enumerate(nums):
            sm += -1 if num == 0 else 1
            if sm in memo:
                ans = max(ans, idx - memo[sm])
            else:
                memo[sm] = idx
        return ans
        