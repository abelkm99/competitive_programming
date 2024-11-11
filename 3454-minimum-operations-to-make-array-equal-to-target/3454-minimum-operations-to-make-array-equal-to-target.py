class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        ans = 0

        def solve(arr: list[int]) -> int:
            ans = abs(arr[0])
            for i in range(1, len(arr)):
                ans += max(0, abs(arr[i]) - abs(arr[i - 1]))
            return ans
        
        diff = [0] * len(nums)
        for i in range(len(nums)):
            diff[i] = target[i] - nums[i]
        i = 0
        groups = []
        while i < len(nums):
            tmp = []
            j = i
            while j < len(nums) and (diff[i] < 0) == (diff[j] < 0):
                # print(i, j)
                tmp.append(diff[j])
                j += 1
            groups.append(tmp)
            i = j
        return sum(solve(x) for x in groups)
