class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 and mp.find(nums[i]) != mp.end()) continue;
            int m = i+1;
            int n = nums.size()-1;
            int target = -nums[i];
            
            while(m < nums.size() && n >= 0 && m > i && n > i && m < n)
            {
                if(nums[m] + nums[n] == target){ 
                    res.push_back({nums[i], nums[m], nums[n]}); 
                    mp.insert({nums[i], 1});
                    //mp.insert({nums[m], 1});
                    //mp.insert({nums[n], 1});
                    m++; 
                    while(m != 0 && nums[m] == nums[m-1]) m++;
                    n--;
                    while(n < nums.size()-1 && nums[n] == nums[n+1]) n--;
                }
                else if(nums[m] + nums[n] < target) m++;
                else n--;
            }
        }
        
        return res;
    }
};
