class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0;
        priority_queue<pair<int, int>> mq;
        for(int r = 0; r < nums.size(); r++){
            if(r-l+1 <= k) mq.push({nums[r], r});
            if(r-l+1 == k){
                while(mq.top().second < l) mq.pop();
                res.push_back(mq.top().first);
                l++;
            }
        }
        return res;
    }
};
