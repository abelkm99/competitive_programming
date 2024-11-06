class Solution:
    def numDecodings(self, s: str) -> int:
        # if previous is 0 or any number greater than 2  don't check
        # if current is 0 -> don't check this case
        # if 1 < 2
        ways = [0] * len(s)

        for i, c in enumerate(s):
            case_1, case_2 = 0, 0
            if c != "0":
                case_1 = ways[i - 1] if i > 0 else 1
            if i > 0 and s[i - 1] != "0" and int(s[i-1] + s[i]) <= 26:
                case_2 = ways[i - 2] if i > 1 else 1
            ways[i] = case_1 + case_2

        return ways[-1]