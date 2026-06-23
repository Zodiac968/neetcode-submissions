class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], i});
        }
        sort(cars.begin(), cars.end());
        stack<int> fleets;
        for(int i = cars.size()-1; i >= 0; i--){
            if(fleets.empty()){
                fleets.push(cars[i].second);
            }
            else{
                float tTop = (float)(target - position[fleets.top()]) / speed[fleets.top()];
                float tCurr = (float)(target - cars[i].first) / speed[cars[i].second];
                if(tCurr > tTop) fleets.push(cars[i].second);  
            }
        }
        return fleets.size();
    }
};
