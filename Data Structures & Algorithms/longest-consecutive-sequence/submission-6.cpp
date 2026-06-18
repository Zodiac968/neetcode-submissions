class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, int> freq;
        for(int num : nums){
            if(freq.find(num) != freq.end()) continue;
            freq.insert({num, 1});
        }
        int highest = 1;
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]-1) == freq.end()){
                int c = 1;
                int num = nums[i]+1;
                while(freq.find(num) != freq.end()) {
                    c++;
                    num++;
                }
                if(highest < c) highest = c;
            }
        }
        return highest;
    }
};
