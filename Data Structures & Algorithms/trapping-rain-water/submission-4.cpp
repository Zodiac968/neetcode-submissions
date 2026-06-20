class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        vector<int> water;
        vector<int> hr(height.size());
        vector<int> hl;
        int greatestRight = height[r];
        int greatestLeft = height[l];
        while(r >= 0){
            greatestRight = max(greatestRight, height[r]);
            hr[r] = greatestRight;
            r--;
        }
        while(l < height.size()){
            greatestLeft = max(greatestLeft, height[l]);
            hl.push_back(greatestLeft);
            l++;
        }
        for(int i = 0; i < height.size(); i++){
            if(i == 0) continue;
            else if(i == height.size() - 1) continue;
            int trappedWater = min(hl[i], hr[i]) - height[i];
            water.push_back(trappedWater);
        }
        int area = 0;
        for(int i = 0; i < water.size(); i++){
            area += water[i];
        }
        return area;
    }
};
