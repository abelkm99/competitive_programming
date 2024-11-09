class Solution:
    def isHappy(self, n: int) -> bool:
        st = set()
        while n != 1:
            n = sum([int(c)**2 for c in str(n)])
            if n == 1:
                return True
            if n in st:
                return False
            st.add(n)
        
        return False