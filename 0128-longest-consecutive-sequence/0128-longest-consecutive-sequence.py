class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        ans = 0
        for num in nums:
            if num - 1 in st:
                continue
            cnt = 0
            curr = num
            while curr in st:
                cnt += 1
                curr += 1
            ans = max(ans, cnt)

        return ans