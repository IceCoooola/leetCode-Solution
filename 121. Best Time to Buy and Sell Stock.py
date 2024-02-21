class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minimum, profit = float('inf'), 0
        for price in prices:
            if price < minimum:
                minimum = price
            profit = max(price - minimum, profit)
        return profit
