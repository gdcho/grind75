# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low, high = 0, n
        result = n
        while low <= high:
            if isBadVersion((low + high) // 2):
                result = (low+high)//2
                high = ((low+high)//2) -1
            else:
                low = ((low+high)//2)+1
        return result


        
