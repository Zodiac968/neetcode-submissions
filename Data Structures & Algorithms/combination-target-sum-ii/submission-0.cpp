class Solution {
public:
    void findComb(vector<int>& candidates, int target, int sum, int index, vector<int>& base, vector<vector<int>>& res){
        if(sum == target){
            res.push_back(base);
            return;
        }
        if(sum > target) return;
        for(int i = index; i < candidates.size(); i++){
            if(i != 0 && i != index && candidates[i-1] == candidates[i]) continue;
            sum += candidates[i];
            base.push_back(candidates[i]);
            findComb(candidates, target, sum, i+1, base, res);
            sum -= candidates[i];
            base.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> base;
        sort(candidates.begin(), candidates.end());
        findComb(candidates, target, 0, 0, base, res);
        return res;
    }
};
