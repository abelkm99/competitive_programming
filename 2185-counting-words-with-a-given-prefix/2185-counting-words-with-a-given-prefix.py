class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ln = len(pref)
        cnt = 0
        for x in words:
            if(x[:ln] == pref):
                cnt += 1
        return cnt