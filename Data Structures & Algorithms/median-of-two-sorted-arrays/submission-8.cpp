class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1.size() + nums2.size();
        int half = ceil((double)t/2);
        vector<int> curr = nums1;
        vector<int> other = nums2;
        if(curr.size() > other.size()){
            vector<int> temp = curr;
            curr = other;
            other = temp;
        }
        if(curr.size() == 0){
            if(t%2 == 0) return (double)(other[half-1]+other[half])/2;
            else return other[half-1];
        }
        int l = 0;
        int r = curr.size();
        while(true){
            int m = (r+l)/2;
            int cl, cr, otl, otr;

            if(m-1 < 0) cl = INT_MIN;
            else cl = curr[m-1];
            if(m >= curr.size()) cr = INT_MAX;
            else cr = curr[m];
            if(half - m >= curr.size()) otr = INT_MAX;
            else otr = other[half - m];
            if(half-m-1 < 0) otl = INT_MIN;
            else otl = other[half - m - 1];

            if(cl <= otr && otl <= cr){
                if(t%2 == 0){
                    return (double)(max(cl, otl)+min(cr, otr))/2;
                }
                else return max(cl, otl);
            }
            else if(cl > otr) r = m-1;
            else l = m+1;
        }
        return 1;
    }
};
