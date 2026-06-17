class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int n = -1;
        while(l <= r){
            int m = (r+l)/2;
            if(nums[m-1] > nums[m]){
                n = m;
                break;
            }
            else if(nums[l] > nums[m]){
                r = m-1;
            }
            else if(nums[r] < nums[m]){
                l = m+1;
            }
            else{
                n = l;
                break;
            }
        }
        l = 0;
        r = nums.size()-1;
        while(l <= r){
            int m = (r+l)/2;
            int mm = (m+n)%nums.size();
            if(nums[mm] == target) return mm;
            else if(nums[mm] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
