class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key) == mp.end()){
            mp.insert({key, {{timestamp, value}}});
        }
        else{
            mp[key].push_back({timestamp, value});
        }
    }
    
    string get(string key, int timestamp) {
        // /*
        int l = 0;
        int r = mp[key].size() - 1;
        int prev_m = -1;
        cout << timestamp << endl;
        while(l <= r){
            int m = (r+l)/2;
            if(mp[key][m].first == timestamp){
                return mp[key][m].second;
            }
            else if(mp[key][m].first > timestamp){
                r = m-1;
            }
            else{
                prev_m = m;
                l = m+1;
            }
        }
        if(prev_m == -1) return "";
        return mp[key][prev_m].second;
        // */
    }
};
