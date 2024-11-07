class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        # for the max so far i can forget about it 
        # max so far can be the min * curr, max * curr, or just the curr

        mn = nums[0]
        mx = nums[0]
        ans = nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            tmp_mx = max(mn * num, mx * num, num)
            tmp_mn = min(mn * num, mx * num, num)
            mn, mx = tmp_mn, tmp_mx
            ans = max(ans, mn, mx)
        
        return ans
