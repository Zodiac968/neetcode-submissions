class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = -1;
        int m = 0;
        int n = heights.size()-1;
        while(m < heights.size() && n >= 0 && m < n){
            int area = (n-m) * min(heights[m], heights[n]);
            cout << heights[m] << " " << heights[n] << " " << area << endl;
            if(area > max) max = area;
            if(heights[m] < heights[n]) m++;
            else n--;
        }
        return max;
    }
};
