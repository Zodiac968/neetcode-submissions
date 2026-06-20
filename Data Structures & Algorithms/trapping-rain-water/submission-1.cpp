class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = 1;
        vector<int> water;
        for(int i = 0; i < height.size(); i++){
            int left = height[i];
            int right = height[i];
            if(i == 0) continue;
            else if(i == height.size() - 1) continue;
            for(int j = i + 1; j < height.size(); j++){
                if(right < height[j]) right = height[j]; 
            }
            for(int j = i-1; j >= 0; j--){
                if(left < height[j]) left = height[j];
            }
            int trappedWater = min(left, right) - height[i];
            water.push_back(trappedWater);
        }
        int area = 0;
        for(int i = 0; i < water.size(); i++){
            area += water[i];
        }
        return area;
    }
};
