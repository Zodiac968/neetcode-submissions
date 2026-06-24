class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = (r+l)/2;

            if(nums[m] == target) return m;
            else if(nums[l] <= nums[m] && (target < nums[m] && target >= nums[l])){
                r = m-1;
            }
            else if(nums[l] <= nums[m]){
                l = m+1;
            }
            else if(nums[r] >= nums[m] && (target > nums[m] && target <= nums[r])){
                l = m+1;
            }
            else if(nums[r] >= nums[m]) r = m-1;
        }
        return -1;
    }
};
