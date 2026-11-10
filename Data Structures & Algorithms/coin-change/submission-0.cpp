class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                int c = coins[j];
                if(i - c < 0) continue;
                if(dp[i-c] == 0 && i-c != 0) continue;
                dp[i] = min(dp[i] == 0 ? INT_MAX : dp[i], dp[i-c]+1);
            }
            cout << i << " : " << dp[i] << endl;
        }
        if(amount == 0) return 0;
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};
