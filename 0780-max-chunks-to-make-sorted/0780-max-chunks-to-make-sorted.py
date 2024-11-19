class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        cnt = 1

        for num in arr:
            mx = num
            while stack and stack[-1] > num:
                v = stack.pop()
                mx = max(mx, v)
                
            stack.append(mx)

        return len(stack)