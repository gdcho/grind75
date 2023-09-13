class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dic = {}
        for i in ransomNote:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        for i in magazine:
            if i in dic:
                dic[i] -= 1
                if dic[i] == 0:
                    del dic[i]
        return not len(dic)
        
        