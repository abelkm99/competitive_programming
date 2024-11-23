from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        s = list(s)
        cnt = Counter(s)

        s.sort(key=lambda x: cnt[x], reverse=True)
        return "".join(s)


        