class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        @cache
        def solve(l:int, r:int) -> int:
            if r == len(t):
                return 1
            if l == len(s):
                return 0
            
            case_1 = solve(l + 1, r) # don't pick
            case_2 = 0
            if s[l] == t[r]:
                case_2 = solve(l + 1, r + 1)

            return case_1 + case_2
        
        return solve(0, 0)