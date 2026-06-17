class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]) == freq.end()) freq.insert({nums[i], 1});
            else {
                return true;
            }
        }
        return false;
    }
};