class Solution:
    def putMarbles(self, A: List[int], k: int) -> int:
        if k == 1 or k == len(A):
            return 0
        pairs = []
        for i in range(1,len(A)):
            pairs.append(A[i] + A[i - 1])

        pairs.sort()
        k -= 1
        # print(pairs)
        return sum(pairs[-k:]) - sum(pairs[:k])