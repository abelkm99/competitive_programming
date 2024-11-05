class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        heights.insert(0, float("-inf"))
        heights.append(float("-inf"))
        dp = [[i, i] for i in range(len(heights))]
        stack: list[int] = []



        ans = 0
        for idx, h in enumerate(heights):
            # answer the question here
            while stack and  heights[stack[-1]] > h:
                dp[stack[-1]][0] = idx # idx is the next samlles element
                stack.pop()
            if stack:
                dp[idx][1] = stack[-1] # the prev element is the previous smallest element
            stack.append(idx)

        for (r, l), h in zip(dp[1:-1], heights[1:-1]):
            ans = max(ans, (r - l - 1) * h)

        return ans
        