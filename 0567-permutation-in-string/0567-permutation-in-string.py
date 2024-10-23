class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # for i in range (len())

        counter = [0] * 26
        for c in s1:
            counter[ord(c) - ord("a")] += 1
        
        l, r = 0, 0
        
        cp = counter.copy()

        for r in range(len(s2)):
            idx = ord(s2[r]) - ord("a")
            cp[idx] -= 1

            while cp[idx] < 0:
                cp[ord(s2[l]) - ord("a")] += 1
                l += 1

            if sum(cp) == 0:
                return True

        return False