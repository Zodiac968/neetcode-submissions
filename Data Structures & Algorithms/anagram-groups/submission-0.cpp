class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> sorted;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(sorted.find(s) == sorted.end()){
                sorted[s] = sorted.size();
                res.push_back({strs[i]});
            }
            else{
                res[sorted[s]].push_back(strs[i]);
            }
        }
        return res;
    }
};
