class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sum = ""
        for i in digits:
            sum += str(i)
        res = [int(x) for x in str(int(sum)+1)]
        return res
            
            