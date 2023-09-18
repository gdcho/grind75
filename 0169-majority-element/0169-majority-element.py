class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        limit = len(nums) // 2
        dic = {}
        for i in nums:
            dic[i] = 1 + dic.get(i, 0)
            if dic[i] > limit:
                return i
        
            
        


        