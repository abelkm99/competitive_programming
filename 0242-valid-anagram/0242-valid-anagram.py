class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a, b = [0] * 26, [0] * 26
        for x in s:
            a[ord(x) - ord('a')] += 1
        for x in t:
            b[ord(x) - ord('a')] += 1
        return a == b