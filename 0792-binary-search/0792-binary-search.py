class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) -1

        while l <= r:
            md = (r - l // 2) + l
            if nums[md] == target:
                return md
            if nums[md] > target:
                r = md - 1
            else:
                l = md + 1
        return -1