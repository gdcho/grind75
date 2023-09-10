class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num = {}
        for x in range(len(nums)):
            if target-nums[x] in num:
                return [num[target-nums[x]], x]
            num[nums[x]] = x
        return []
        