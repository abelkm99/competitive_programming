class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        times = [(position[i], (target - position[i]) / speed[i]) for i in range(n)]
        times.sort(reverse=True)
        stack = []
        # print(times)
        for _, tm in times:
            if stack and tm <= stack[-1]:
                continue
            stack.append(tm)
        return len(stack)