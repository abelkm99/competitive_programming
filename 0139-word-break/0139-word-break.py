class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:



        # i want to check if the current index exits or not
        # how will i do that.
        # from here to the end
        wordDict = set(wordDict)
        n = len(s) + 1
        dp = [[0 for _ in range(n)] for _ in range(n)]

        dp[0][0] = 1

        for i in range(1,n):
            for j in range(i, n):
                wrd = s[i - 1:j]
                dp[i][j] = dp[i - 1][j] or (dp[i - 1][i - 1] if wrd in wordDict else 0)
                # print(i, j, wrd, "res ",dp[i][j])

        
        return dp[n - 1][n - 1] == 1
