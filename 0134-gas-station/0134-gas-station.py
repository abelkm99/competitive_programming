class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(cost) > sum(gas):
            return -1
        
        ans = 0
        g, c = 0, 0

        for i in range(len(gas)):

            g += gas[i]
            c += cost[i]

            if c > g:
                ans = i + 1
                g, c = 0, 0
        
        return ans
