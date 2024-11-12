class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:


        @cache
        def split(idx, k) -> int:
            if idx == len(nums):
                return 0 if k == 0 else float("inf")
            if k == 0:
                return float("inf")
            

            ans = float("inf")
            sm = 0
            for i in range(idx, len(nums)):
                sm += nums[i]
                val = split(i + 1, k - 1)
                ans = min(ans, max(sm, val))

            return ans

        return split(0, k)