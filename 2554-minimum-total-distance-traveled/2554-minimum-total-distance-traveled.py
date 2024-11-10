class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:

        f = []
        for pos, limit in factory:
            f.extend([pos] * limit)
        
        robot.sort()
        f.sort()

        memo = {}
        def solve(i: int, j: int) -> int:
            if (i, j) in memo:
                return memo[(i, j)]
            if i == len(robot):
                return 0
            if j == len(f):
                return float("inf")
            
            pick = solve(i + 1, j + 1) + abs(robot[i] - f[j])
            dont = solve(i, j + 1)
            # print(i, j, pick, dont)

            ans = min(pick, dont)
            memo[(i, j)] = ans
            return ans
        
        ans = solve(0, 0)
        del memo
        return ans