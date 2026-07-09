class Solution {
public:
    void perm(vector<int>& nums, vector<vector<int>>& res, vector<int>& base, unordered_map<int, int>& freq){
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
            if(freq.find(i) != freq.end() && freq[i] == 1){
                i++;
                continue;
            }
            base.push_back(i);
            freq[i] = 1;
            perm(nums, res, base, freq);
            base.pop_back();
            freq[i] = 0;
            i++;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> base;
        unordered_map<int, int> freq;
        perm(nums, res, base, freq);
        return res;
    }
};
