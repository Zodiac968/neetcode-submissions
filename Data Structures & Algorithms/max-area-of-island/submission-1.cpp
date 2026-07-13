class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int s = 0;
    int maxRank = 0;
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool merge(int u, int v){
        int ur = find(u);
        int vr = find(v);
        if(ur == vr) return false;
        else if(rank[ur] >= rank[vr]){
            rank[ur] += rank[vr];
            if(rank[ur] > maxRank) maxRank = rank[ur];
            parent[vr] = ur;
        }else{
            rank[vr] += rank[ur];
            if(rank[vr] > maxRank) maxRank = rank[vr];
            parent[ur] = vr;
        }
        return true;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        s = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                rank.push_back(1);
                parent.push_back(i*s+j);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    if(maxRank == 0) maxRank = 1;
                    if(i+1 < grid.size() && grid[i+1][j] == 1) merge(i*s+j, (i+1)*s+j);
                    if(j+1 < s && grid[i][j+1] == 1) merge(i*s+j, i*s+j+1);
                }
            }
        }
        return maxRank;
    }
};
