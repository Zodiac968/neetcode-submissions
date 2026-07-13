class Solution {
public:

    vector<int> rank;
    vector<int> parent;

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void mergeNeighbours(vector<vector<char>>& grid, int j, int i, int x, int y, int &count){
        if(x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size()) return;
        if(grid[y][x] == '1'){
            int u = find(i*grid[0].size()+j);
            int v = find(y*grid[0].size()+x);
            if(u == v) return;
            else if(rank[u] >= rank[v]){
                rank[u] += rank[v];
                parent[v] = u;
            }else{
                rank[v] += rank[u];
                parent[u] = v;
            }
            count--;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int s = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    // rank[i*s+j] = 1;
                    // parent[i*s+j] = i*s+j;
                    rank.push_back(1);
                    parent.push_back(i*s+j);
                }
                else {
                    rank.push_back(0);
                    parent.push_back(0);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    mergeNeighbours(grid, j, i, j+1, i, count);
                    mergeNeighbours(grid, j, i, j, i+1, count);
                }
            }
        }
        return count;
    }
};
