class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixProd(nums.size());
        vector<int> suffixProd(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) prefixProd[i] = 1;
            else prefixProd[i] = prefixProd[i-1] * nums[i-1];

            if(size - 1 - i == size - 1) suffixProd[size - 1 - i] = 1;
            else suffixProd[size - i - 1] = suffixProd[size - i] * nums[size - i]; 
        }
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            res[i] = prefixProd[i] * suffixProd[i];
        }
        return res;
    }
};
