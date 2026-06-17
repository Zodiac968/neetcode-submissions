class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, profit = 0; 
        for(int r = 0; r < prices.size(); r++){
            int price = prices[r] - prices[l];
            if(price > profit) profit = price;
            if(prices[r] < prices[l]) l = r;
        }
        return profit;
    }
};
