class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> inp;
        for(int i = 0; i < position.size(); i++){
            inp.push_back({position[i], speed[i]});
        }
        sort(inp.begin(), inp.end());
        vector<float> time;
        for(int i = 0; i < inp.size(); i++) 
            time.push_back((float)(target - inp[i].first)/(float)inp[i].second);
        int fleets = 1;
        int disconnect = 1;
        for(int i = time.size()-2; i >= 0; i--){
            if(time[i] <= time[i+1]) {
                time[i] = time[i+1];
                continue;
            }
            else{
                fleets++;
            }
        }
        return fleets;
    }
};
