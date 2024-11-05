class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans: list[list[int]] = []
        for i, v in enumerate(nums):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                tot = nums[i] + nums[l] + nums[r]
                if tot == 0:
                    ans.append([nums[i], nums[l], nums[r]])
                if tot >= 0:
                    val = nums[r]
                    while l < r and nums[r] == val:
                        r -= 1
                if tot <= 0:
                    val = nums[l]
                    while l < r and nums[l] == val:
                        l += 1
        return ans