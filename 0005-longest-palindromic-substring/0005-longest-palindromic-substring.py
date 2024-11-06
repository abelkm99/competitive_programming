class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[0 for i in range(n)] for i in range(n)]
        mx = 0
        start, end = 0, 0
        for r in range(n):
            for l in range(r+1):
                if s[l] == s[r]:
                    # this is where we play the game
                    if l == r:
                        dp[r][l] = 1
                    else:
                        # check if the previous is also palindrom if it's just two string
                        if r - l < 2:
                            dp[r][l] = 2
                        elif dp[r - 1][l + 1]:
                            dp[r][l] = dp[r - 1][l + 1] + 2
                    if dp[r][l] > mx:
                        start, end = l, r
                        mx = dp[r][l]
        return s[start:end + 1]