class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // min-heap
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = 1;
            else mp[nums[i]]++;
        }
        for(auto &p : mp){
            pq.push({p.second, p.first});
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
