class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int> heap;
        int buy = 0;
        int sell = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < prices[i-1])
            {
                heap.push(prices[sell] - prices[buy]);
                sell = i;
                buy = i;
            }
            else
            {
                if(prices[i] - prices[buy] >= prices[sell] - prices[buy])
                {
                    sell = i;
                }
            }
        }
        if(sell == prices.size()-1)
        {
            heap.push(prices[sell] - prices[buy]);
        }

        int profit = 0;
        while(!heap.empty())
        {
            profit+= heap.top();
            heap.pop();
        }
        return profit;
    }
};
