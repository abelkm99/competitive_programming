class Solution:
    def compressedString(self, word: str) -> str:
        l = 0
        ans = []
        while l < len(word):
            i = l
            while i < len(word) and word[i] == word[l]:
                i += 1
            dst = i - l
            print(dst)
            while dst >= 9:
                ans.extend([str(9), word[l]])
                dst -= 9
            if dst:
                ans.extend([str(dst), word[l]])
            l = i
        return "".join(ans)
