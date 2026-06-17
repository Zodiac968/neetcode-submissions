class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]) != freq.end()){
                if(i == freq[nums[i]]) continue;
                return {freq[nums[i]], i};
            }
            freq[target-nums[i]] = i;
        }
        return {-1, -1};
    }
};
