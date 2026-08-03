class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int count = 0;

    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool usj(int i, int j){
        int u = find(i);
        int v = find(j);
        if(u == v) return false;
        if(rank[u] < rank[v]){
            rank[v] += rank[u];
            parent[u] = v;
        }
        else{
            rank[u] += rank[v];
            parent[v] = u;
        }
        count--;
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        count = n;
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0; i < edges.size(); i++){
            usj(edges[i][0], edges[i][1]);
        }
        return count;
    }
};
