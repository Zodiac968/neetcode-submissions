class Solution {
public:
    vector<int> parents;
    int find(int i){
        if(parents[i] == i) return i;
        return parents[i] = find(parents[i]);
    }

    bool usj(int x, int y){
        int u = find(x);
        int v = find(y);
        if(u == v) return false;
        else{
            parents[u] = v;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++){
            parents.push_back(i);
        }
        for(int i = 0; i < edges.size(); i++){
            bool res = usj(edges[i][0]-1, edges[i][1]-1);
            if(!res) return edges[i];
        }
        return {-1, -1};
    }
};
