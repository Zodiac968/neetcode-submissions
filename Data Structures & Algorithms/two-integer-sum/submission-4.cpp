class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        vector<int> res = {-1, -1};
        for(int i = 0; i < nums.size(); i++){
            if(freq.count(nums[i])){
                if(i == freq[nums[i]]) continue;
                res[1] = i;
                res[0] = freq[nums[i]];
                return res;
            }
            freq[target-nums[i]] = i;
        }
        // for(int i = 0; i < nums.size(); i++){
        //     if(freq.count(nums[i])){
        //         if(i == freq[nums[i]]) continue;
        //         res[0] = i;
        //         res[1] = freq[nums[i]];
        //         return res;
        //     }
        // }
        return res;
    }
};
