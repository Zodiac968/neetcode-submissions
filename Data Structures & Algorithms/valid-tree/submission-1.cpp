class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int maxRank = 1;

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
            if(maxRank < rank[v]) maxRank = rank[v];
            parent[u] = v;
        }
        else{
            rank[u] += rank[v];
            if(maxRank < rank[u]) maxRank = rank[u];
            parent[v] = u;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0; i < edges.size(); i++){
            bool res = usj(edges[i][0], edges[i][1]);
            if(!res) return false;
        }
        if(maxRank == n) return true;
        return false;
    }
};
