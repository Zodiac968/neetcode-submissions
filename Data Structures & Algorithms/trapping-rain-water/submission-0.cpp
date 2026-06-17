class Solution {
public:
    int trap(vector<int>& height) {
        int m = 0;
        int n = height.size() - 1;
        vector<int> greatestHeight(height.size(), 1001);
        /*
        vector<int> water(height.size());
        for(int i = 0; i < height.size(); i++){
            int greatestLeft = height[i];
            int greatestRight = height[i];
            int foundl = 0;
            int foundr = 0;
            for(int j = 0; j < height.size(); j++){
                if(j < i && height[j] > greatestLeft){
                    foundl = 1;
                    greatestLeft = height[j];
                }
                else if( j > i && height[j] > greatestRight){
                    foundr = 1;
                    greatestRight = height[j];
                }
            }
            if(foundl && foundr) water[i] = min(greatestLeft, greatestRight) - height[i];
        }
        */
        int greatestLeft = 0;
        int greatestRight = 0;
        while(m < height.size() && n >= 0){
            greatestHeight[m] = min(greatestLeft, greatestHeight[m]);
            greatestHeight[n] = min(greatestRight, greatestHeight[n]);
            if(greatestLeft < height[m]){
                greatestLeft = height[m];
            }
            if(greatestRight < height[n]){
                greatestRight = height[n];
            }
            m++;
            n--;
        }
        int trappedWater = 0;
        for(int i = 0; i < greatestHeight.size(); i++){
            int water = greatestHeight[i] - height[i];
            if(water > 0) trappedWater += water;
        }
        return trappedWater;
    }
};
