class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(r-l+1 == k){
                priority_queue<int> mq;
                for(int i = l; i <= r; i++){
                    mq.push(nums[i]);
                }
                res.push_back(mq.top());
                l++;
            }
        }
        return res;
    }
};
