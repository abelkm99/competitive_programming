class Solution:
    def spiralOrder(self, a: List[List[int]]) -> List[int]:
        if not a:
            return []
        rev = [list(x) for x in zip(*a[1:])][::-1]
        return a[0] + self.spiralOrder(rev)