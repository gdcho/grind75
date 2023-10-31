class Solution:
    def mySqrt(self, x: int) -> int:
        root = 0
        while root * root < x:
            if (root+1) * (root+1) > x:
                return root
            elif (root+1) * (root+1) == x:
                return root+1
            root += 1

        return root