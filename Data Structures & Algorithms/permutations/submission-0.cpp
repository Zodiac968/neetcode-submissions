class Solution {
public:
    void perm(vector<int>& nums, vector<vector<int>>& res, vector<int>& base){
        if(base.size() == nums.size()){
            vector<int> ns;
            for(int i = 0; i < base.size(); i++){
                ns.push_back(nums[base[i]]);
            }
            res.push_back(ns);
            return;
        }
        int i = 0;
        while(i < nums.size()){
            bool present = false;
            for(int j = 0; j < base.size(); j++){
                if(nums[base[j]] == nums[i]){
                    present = true;
                    break;
                }
            }
            if(present){
                i++;
                continue;
            }
            base.push_back(i);
            perm(nums, res, base);
            base.pop_back();
            i++;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> base;
        perm(nums, res, base);
        return res;
    }
};
