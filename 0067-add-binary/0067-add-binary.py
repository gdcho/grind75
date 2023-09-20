class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        out = []
        
        a, b = a[::-1], b[::-1]
        
        if len(b) > len(a):
            a, b = b, a
        
        for i in range(len(a)):
            sum_val = carry
            
            if i < len(a):
                sum_val += int(a[i])
            
            if i < len(b):
                sum_val += int(b[i])
            
            if sum_val == 2:
                out.append('0')
                carry = 1
            elif sum_val == 3:
                out.append('1')
                carry = 1
            else:
                out.append(str(sum_val))
                carry = 0
        
        if carry:
            out.append('1')
        
        return ''.join(out[::-1])
