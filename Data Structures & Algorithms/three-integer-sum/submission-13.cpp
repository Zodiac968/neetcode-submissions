class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int n1 = nums[i];
            if(i > 0 && n1 == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size() - 1;
            while(l < r){
                if(n1 + nums[l] + nums[r] == 0){
                    res.push_back({n1, nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
                else if(n1 + nums[l] + nums[r] < 0) l++;
                else r--;
            }
        }
        return res;
    }
};
