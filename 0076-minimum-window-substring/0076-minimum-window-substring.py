class Solution:
    def minWindow(self, s: str, t: str) -> str:

        cnt = Counter(t)


        ln = float("inf")
        ans = ""
        
        def check() -> bool:
            for x in cnt.values():
                if x > 0:
                    return False
            return True

        l = 0
        for r, c in enumerate(s):
            if c not in cnt:
                continue
            cnt[c] -= 1
            while check():
                if r - l + 1 < ln:
                    ans = s[l:r + 1]
                    ln = len(ans)

                if s[l] in cnt:
                    cnt[s[l]] += 1
                l += 1
        
        return ans