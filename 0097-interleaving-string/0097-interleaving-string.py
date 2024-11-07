class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:


        # when i am at p1 at s1 and p3 == s3
        # then i can guess

        @cache
        def check(p1: int, p2: int) -> bool:
            p3 = p1 + p2
            if p3 == len(s3):
                return p1 == len(s1) and p2 == len(s2)
            #
            case_1 = check(p1 + 1, p2) if p1 < len(s1) and s1[p1] == s3[p3] else False
            case_2 = check(p1, p2 + 1) if p2 < len(s2) and s2[p2] == s3[p3] else False

            return case_1 or case_2

        return check(0, 0)