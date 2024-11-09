class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] == 9 and carry:
                digits[i] = 0
                continue
            digits[i] += carry
            carry = 0
        return digits if not carry else [1] + digits
