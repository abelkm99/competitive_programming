class Solution:
    def isValid(self, s: str) -> bool:
        prev = []
        for c in s:
            if c in "({[":
                prev.append(c)
                continue
            if not prev:
                return False
            p = prev.pop()
            if (p == '{' and c == '}') or (p == '[' and c == ']') or (p == '(' and c == ')'):
                continue
            else:
                return False
        return len(prev) == 0
