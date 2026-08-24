class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool connect(int x, int y){
        int u = find(x);
        int v = find(y);
        if(u == v){
            return false;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
            rank[u] += rank[v];
        }else{
            parent[u] = v;
            rank[v] += rank[u];
        }
        return true;
    }

    struct Edge{
        int dist;
        int p1;
        int p2;
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        vector<Edge> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < i; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
            return a.dist < b.dist;
        });
        int cost = 0;
        for(int i = 0; i < edges.size(); i++){
            bool res = connect(edges[i].p1, edges[i].p2);
            if(!res) continue;
            cost += edges[i].dist;
            // cout << "Connected " << edges[i].p1 << " " << edges[i].p2 << " " << edges[i].dist << endl;
        }
        return cost;
    }
};
