class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        ans = 0
        l, cnt = 0, 0
        for r in range(len(nums)):
            cnt += 1 if nums[r] == 0 else 0

            while cnt > k:
                cnt -= 1 if nums[l] == 0 else 0
                l += 1
            ans = max(ans, r - l + 1)
        return ans

            
