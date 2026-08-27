class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        vector<int> dp2(nums.size()+1);
        if(nums.size() == 1) return nums[0];
        if(nums.size() < 1) return -1;
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        } 
        return max(dp[nums.size()-1], dp2[nums.size()-1]);
    }
};
