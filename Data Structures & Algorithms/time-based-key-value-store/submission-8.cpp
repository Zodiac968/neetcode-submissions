class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key) == mp.end()) mp.insert({key, {{value, timestamp}}});
        else{
            mp[key].push_back({value, timestamp});
        }
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty()) return "";
        int l = 0;
        int r = mp[key].size()-1;
        int m;
        while(l <= r){
            m = (r+l)/2;
            if(mp[key][m].second == timestamp) return mp[key][m].first;
            else if(mp[key][m].second < timestamp) {
                l = m+1;
                if(l <= r && mp[key][l].second > timestamp) return mp[key][m].first;
            }
            else r = m-1;
        }
        if(mp[key][m].second > timestamp) return "";
        return mp[key][m].first;
    }
};
