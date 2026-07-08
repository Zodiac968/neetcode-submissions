class Solution {
public:
    void add(vector<int>& nums, vector<int> base, int index, vector<vector<int>>& res){
        res.push_back(base);
        for(int i = index; i < nums.size(); i++){
            vector<int> a = base;
            a.push_back(nums[i]);
            add(nums, a, i+1, res);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        add(nums, {}, 0, res);
        return res;
    }
};
