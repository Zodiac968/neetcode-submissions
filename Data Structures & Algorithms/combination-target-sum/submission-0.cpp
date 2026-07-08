class Solution {
public:
    void addComb(vector<int>& nums, int target, vector<vector<int>>& res, vector<int> base, int sum, int index){
        if(sum == target){
            res.push_back(base);
            return;
        }
        else if(sum > target) return;
        for(int i = index; i < nums.size(); i++){
            sum += nums[i];
            base.push_back(nums[i]);
            addComb(nums, target, res, base, sum, i);
            sum -= nums[i];
            base.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        addComb(nums, target, res, {}, 0, 0);
        return res;
    }
};
