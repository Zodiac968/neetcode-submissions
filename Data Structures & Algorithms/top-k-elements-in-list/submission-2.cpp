class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]) == freq.end()) freq[nums[i]] = 1;
            else freq[nums[i]]++;
        }
        for(auto &p : freq){
            buckets[p.second].push_back(p.first);
        }
        for(int i = buckets.size() -1 ; i >= 0; i--){
            while(k > 0 && buckets[i].size() > 0){
                int el = buckets[i][buckets[i].size()-1];
                res.push_back(el);
                buckets[i].pop_back();
                k--;
            }
            if(k <= 0) break;
        }
        return res;
    }
};
