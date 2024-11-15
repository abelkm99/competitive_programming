
n = (10 ** 6) + 10
primes = [float("inf")] * n
for i in range(2, int(n ** 0.5) + 1):
    if primes[i] != float("inf"):
        continue
    for j in range(i*i, n, i):
        primes[j] = min(i, primes[j])

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        if len(nums) == nums.count(1):
            return 0
        cnt = 0
        # print([(i, x) for i, x in enumerate(primes)])

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                nums[i] = primes[nums[i]]
                cnt += 1
            if nums[i] <= nums[i + 1]:
                continue
            return -1
        return cnt