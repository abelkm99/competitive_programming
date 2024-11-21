class Solution:
    def minPartitions(self, n: str) -> int:
        ans = int(n[-1])
        mx = ans
        for j in range(len(n) - 2, -1, -1):
            tmp = max(0, int(n[j]) - mx)
            ans += tmp
            mx = max(mx, int(n[j]))
        return ans
