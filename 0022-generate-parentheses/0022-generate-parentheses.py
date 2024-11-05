class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        ans: list[str] = []
        s = []
        def recursion(o: int, c: int):
            if o == 0 and c == 0:
                ans.append("".join(s))
            if c > o:
                s.append(")")
                recursion(o, c - 1)
                s.pop()
            if o:
                s.append("(")
                recursion(o - 1, c)
                s.pop()

        recursion(n, n)

        return ans
            