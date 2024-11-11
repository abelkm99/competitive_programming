class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        counter = Counter(nums)
        cnt = 0
        for c in counter.keys():
            if c + k in counter:
                if k == 0 and counter[c] >= 2:
                    cnt += 1
                    continue
                elif k != 0:
                    cnt += 1
        return cnt