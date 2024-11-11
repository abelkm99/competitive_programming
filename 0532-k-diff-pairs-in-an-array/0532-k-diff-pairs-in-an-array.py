class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        counter = Counter(nums)
        cnt = 0
        for c in counter.keys():
            if c + k in counter and (k != 0 or counter[c] >= 2):
                cnt += 1
        return cnt