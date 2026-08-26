class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1001);
        dist[src] = 0;
        for(int i = 0; i < k+1; i++){
            vector<int> temp = dist;
            for(int j = 0; j < flights.size(); j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                if(dist[u] + w < dist[v]){
                    temp[v] = min(dist[u] + w, temp[v]);
                }
            }
            dist = temp;
        }
        if(dist[dst] == 1001) return -1;
        else return dist[dst];
    }
};
