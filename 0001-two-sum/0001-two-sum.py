class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {}
        for i, num in enumerate(nums):
            rem = target - num
            if rem in idx:
                return [idx[rem], i]
            idx[num] = i
            
        raise Exception("not found")