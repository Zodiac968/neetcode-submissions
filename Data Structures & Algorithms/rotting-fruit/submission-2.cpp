class Solution {
public:
    bool checkRotten(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size()) return false;
        if(grid[y][x] == 2) return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> fresh;
        int max = grid.size() * grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) fresh.push({j, i});
            }
        }
        while(!fresh.empty() && max > 0){
            int size = fresh.size();
            queue<pair<int, int>> rotten;
            while(size--){
                auto [x, y] = fresh.front();
                fresh.pop();
                if(checkRotten(grid, x+1, y) || 
                checkRotten(grid, x-1, y) || 
                checkRotten(grid, x, y+1) || 
                checkRotten(grid, x, y-1)){
                    rotten.push({x, y});
                    continue;
                }
                fresh.push({x, y});
            }
            while(!rotten.empty()){
                auto [x, y] = rotten.front();
                rotten.pop();
                grid[y][x] = 2;
            }
            max--;
        }
        if(max == 0) return -1;
        else return grid.size() * grid[0].size() - max;
    }
};
