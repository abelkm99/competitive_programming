class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        # i can return l and r as well ass the distance
        dp = [[-1 for _ in range(len(s))] for _ in range(len(s))]
        def solve(l: int, r: int):
            if r < l:
                return (0, 0, 0)

            if dp[l][r] != -1:
                return dp[l][r]

            if l == r:
                dp[l][r] = (1, l, r)
                return dp[l][r]
                
            if s[l] == s[r]:
                # check if it's palindrom from here
                p, q = l, r
                while p <= q and s[p] == s[q]:
                    p += 1
                    q -= 1
                if p > q:
                    dp[l][r] = (r - l + 1, l, r)
                    return dp[l][r]

            case_2 = solve(l + 1, r)
            case_3 = solve(l, r - 1)
            dp[l][r] = max(case_2, case_3)
            return dp[l][r]
        
        _, l, r = solve(0, len(s) - 1)
        # print(l, r)
        return s[l:r + 1]
