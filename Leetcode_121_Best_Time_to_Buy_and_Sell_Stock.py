class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxP = 0
        minP = float('inf') # in python, the limit num
        
        for i in prices:
            minP = min(minP, i)
            profit = i - minP
            maxP = max(maxP, profit)
        
        return maxP