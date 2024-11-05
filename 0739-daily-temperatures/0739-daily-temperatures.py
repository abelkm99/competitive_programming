class Solution:
    def dailyTemperatures(self, arr: List[int]) -> List[int]:
        ans: list[int] = [0] * len(arr)
        mds: list[int] = []
        for i, t in enumerate(arr):
            while mds and arr[mds[-1]] < t:
                ans[mds[-1]] = i - mds[-1]
                mds.pop()

            mds.append(i)

        return ans
