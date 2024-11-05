class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l: int = 0
        counter: dict[str, int] = defaultdict(int)
        ans: int = 0

        def can(k: int):
            sm, mx = 0, 0
            for x in counter.values():
                sm += x
                mx = max(mx, x)
            return k >= sm - mx

        for r, c in enumerate(s):
            counter[c] += 1
            while not can(k):
                counter[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans