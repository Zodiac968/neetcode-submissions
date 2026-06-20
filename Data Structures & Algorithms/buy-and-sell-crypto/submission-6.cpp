class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = prices[0];
        for(int i = 0; i < prices.size(); i++){
            lowestPrice = min(lowestPrice, prices[i]);
            if(lowestPrice < prices[i]){
                maxProfit = max(maxProfit, prices[i] - lowestPrice);
            }
        }
        return maxProfit;
    }
};
