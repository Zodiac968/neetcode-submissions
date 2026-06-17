class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = 0;
        while(l <= r){
            int m = (r+l)/2;

            if(nums[m-1] > nums[m]){
                return nums[m];
            }
            if(nums[l] > nums[m]){
                r = m-1;
            }
            else if(nums[r] < nums[m]){
                l = m+1;
            }
            else{
                return nums[l];
            }
        }
        return -1;
    }
};
