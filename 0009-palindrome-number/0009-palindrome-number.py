class Solution:
    def isPalindrome(self, x: int) -> bool:

        a = "".join(list(str(x))[::-1])
        return str(x) == a
        