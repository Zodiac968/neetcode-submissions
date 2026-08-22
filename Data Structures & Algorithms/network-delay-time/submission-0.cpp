class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTimes(n+1, 1001);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        minTimes[k] = 0;
        pq.push({minTimes[k], k});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(int i = 0; i < times.size(); i++){
                if(times[i][0] != u) continue;
                if(minTimes[times[i][1]] > minTimes[u] + times[i][2]){
                    minTimes[times[i][1]] = minTimes[u] + times[i][2];
                    pq.push({minTimes[times[i][1]], times[i][1]});
                }
            }
        }
        int time = 0;
        for(int i = 1; i <= n; i++){
            if(minTimes[i] == 1001) return -1;
            if(time < minTimes[i]) time = minTimes[i];
        }
        return time;
    }
};