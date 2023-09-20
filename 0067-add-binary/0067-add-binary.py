class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a, b = b, a
        ans = ""
        carry = 0
        a, b = a[::-1], b[::-1]
        l1, l2 = len(a), len(b)
        for i in range(l1):
            t = carry
            t += int(a[i])
            if i < l2:
                t += int(b[i])
            t, carry = t % 2, t // 2
            ans += str(t)
        if carry:
            ans += str(carry)
        return ans[::-1]