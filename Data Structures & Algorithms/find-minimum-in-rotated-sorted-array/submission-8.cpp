class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = (l+r)/2;

            if(nums[m] < nums[(m-1+nums.size())%nums.size()]) return nums[m];
            else if(nums[(m+1)%nums.size()] < nums[m]) return nums[(m+1)%nums.size()];
            else if(nums[l] > nums[m]) r = m;
            else if(nums[r] < nums[m]) l = m;
            else return nums[0];
        }
        return 1;
    }
};
