class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = 0;
        while(l < r){
            int m = (r+l)/2;
            if(nums[(m+n-1)%nums.size()] > nums[(m+n)%nums.size()]){
                return nums[(m+n)%nums.size()]; 
            }
            else{
                n++;
                l = m;
            }
        }
        return nums[l];
    }
};
