class Solution:
    def parseBoolExpr(self, s: str) -> bool:
        s = s.replace('f','False')
        s = s.replace('t','True')
        # print(s)
        s = s.replace("!", "not |")
        s = s.replace("&(", 'all([')
        s = s.replace("|(", "any([")
        s = s.replace(')','])')
        # print(s)
        return eval(s)