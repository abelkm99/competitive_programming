class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:



        # i want to check if the current index exits or not
        # how will i do that.
        # from here to the end
        wordDict = set(wordDict)

        @cache
        def dfs(idx: int, start: int):
            if idx == len(s):
                return idx == start

            case_1, case_2 = False, False
            wrd = s[start:idx + 1]
            if wrd in wordDict:
                # mean i can break it here
                case_1 = dfs(idx + 1, idx + 1)

            case_2 = dfs(idx+1, start)
            return case_1 or case_2
        
        return dfs(0, 0)
