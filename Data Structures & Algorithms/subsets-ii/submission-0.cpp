class Solution {
public:

    void subset(vector<int>& nums, vector<vector<int>>& res, vector<int>& base, int index){
        res.push_back(base);
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i-1] == nums[i]) continue;
            base.push_back(nums[i]);
            subset(nums, res, base, i+1);
            base.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> base;
        sort(nums.begin(), nums.end());
        subset(nums, res, base, 0);
        return res;        
    }
};
