class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        first = 0
        second = 1
        profit = 0

        while second < len(prices):
            if prices[first] < prices[second]:
                profit = max(profit, prices[second]-prices[first])
            else:
                first = second
            second +=1
        return profit


        
