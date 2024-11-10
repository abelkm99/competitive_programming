class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:

        base = (intLength + 1) // 2
        n = 10 ** (base - 1)
        rng = ((10 ** (base)) - 1) - n + 1
        ans = []

        is_odd = intLength & 1

        for q in queries:
            if 1 <= q <= rng:
                tmp = n + q - 1
                val = str(tmp) + (str(tmp)[:-1] if is_odd else str(tmp))[::-1]
                # print(val)
                # val = str(tmp) + (str(tmp[:-1]) if is_odd else str(tmp))[:-1]
                ans.append(int(val))
            else:
                ans.append(-1)
        return ans
        