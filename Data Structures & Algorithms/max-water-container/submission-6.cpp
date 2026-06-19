class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = -1;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int a = (r - l) * min(heights[l], heights[r]);
            if(a > area) area = a;
            if(heights[l] > heights[r]) r--;
            else l++;
        }
        return area;
    }
};
