class Solution {
public:
    #define INF 2147483647
    bool checkValid(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y){
        if(x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size()) return false;
        if(grid[y][x] == -1 || visited[y][x] == 1) return false;
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        queue<pair<int, int>> q;
        queue<pair<int, int>> qL;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            while(!q.empty()){
                qL.push(q.front());
                q.pop();
            }
            while(!qL.empty()){
                int x = qL.front().second;
                int y = qL.front().first;
                qL.pop();
                grid[y][x] = min(level, grid[y][x]);
                visited[y][x] = 1;
                if(checkValid(grid, visited, x+1, y)) q.push({y, x+1});
                if(checkValid(grid, visited, x-1, y)) q.push({y, x-1});
                if(checkValid(grid, visited, x, y+1)) q.push({y+1, x});
                if(checkValid(grid, visited, x, y-1)) q.push({y-1, x});
            }
            level++;
        }
    }
};
