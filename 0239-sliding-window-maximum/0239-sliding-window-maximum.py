class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        ans: list[int] = []
        for i in range(k):
            while dq and dq[-1][0] <= nums[i]:
                dq.pop()
            dq.append((nums[i], i))
        ans.append(dq[0][0])
        for i in range(k, len(nums)):
        #     # delete it if it's its 
            while dq and dq[-1][0] <= nums[i]:
                dq.pop()
            dq.append((nums[i], i))
            if dq[0][1] <= i - k:
                dq.popleft()
            ans.append(dq[0][0])
        return ans