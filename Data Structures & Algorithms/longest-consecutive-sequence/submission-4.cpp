class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> startElements;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i] - 1) == freq.end()) startElements.push_back(nums[i]);
        }
        int maxLen = 0;
        for(int i = 0; i < startElements.size(); i++){
            int len = 1;
            int curr = startElements[i];
            while(freq.find(++curr) != freq.end()) len++;
            if(maxLen < len) maxLen = len;
        }
        return maxLen;
    }
};
