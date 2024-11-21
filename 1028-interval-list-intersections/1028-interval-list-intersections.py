class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        ans: list[list[int]] = []
        t = 0
        b = 0
        while t < len(firstList):
            # increment b till the values of 
            print(t, b)
            while b < len(secondList) and secondList[b][0] <= firstList[t][1]:
                i = max(firstList[t][0], secondList[b][0])
                j = min(firstList[t][1], secondList[b][1])
                if i <= j:
                    ans.append([i, j])
                b += 1

            t += 1
            b = max(0, b - 1)

        return ans
