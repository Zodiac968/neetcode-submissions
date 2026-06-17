class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> prefix;
        vector<int> suffix;
        int prod1 = 1;
        int prod2 = 1;
        for(int i = 0; i < nums.size(); i++){
            prefix.push_back(prod1);
            prod1 *= nums[i];
            suffix.push_back(prod2);
            prod2 *= nums[nums.size()-i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            res.push_back(prefix[i] * suffix[nums.size()-i-1]);
        }
        return res;
    }
};
