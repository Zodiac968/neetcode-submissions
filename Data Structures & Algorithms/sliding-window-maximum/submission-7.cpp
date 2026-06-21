class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        int l = 0;
        int r = 0;
        int max = 0;
        while(r < nums.size()){
            pq.push({nums[r], r});
            if(r-l+1 == k){
                res.push_back(pq.top().first);
                l++;
                while(!pq.empty() && pq.top().second < l) pq.pop();
            }
            r++;
        }
        return res;
    }
};
