class Solution {
public:
    int check(int i, int j, int height, vector<vector<int>>& grid, vector<vector<int>>& heights){
        if(i < 0 || j < 0) return 1;
        if(i >= grid.size() || j >= grid[0].size()) return 2;
        if(height < heights[i][j]) return 0;
        return grid[i][j];
    }

    int dfs(vector<vector<int>>& heights, vector<vector<int>>& grid, int i, int j, int prev){
        if(i < 0 || j < 0) return 1;
        if(i >= grid.size() || j >= grid[0].size()) return 2;
        if(heights[i][j] > prev) return 0;
        if(grid[i][j] != -1){
            return grid[i][j];
        }
        grid[i][j] = 0;
        int a = dfs(heights, grid, i+1, j, heights[i][j]);
        int b = dfs(heights, grid, i-1, j, heights[i][j]);
        int c = dfs(heights, grid, i, j+1, heights[i][j]);
        int d = dfs(heights, grid, i, j-1, heights[i][j]);
        if(a == 1 || b == 1 || c == 1 || d == 1) grid[i][j] = 1;
        if(a == 2 || b == 2 || c == 2 || d == 2){
            if(grid[i][j] == 0) grid[i][j] = 2;
            else grid[i][j] = 3;
        } 
        if(a == 3 || b == 3 || c == 3 || d == 3) grid[i][j] = 3;
        return grid[i][j];
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<int>> grid(heights.size(), vector<int>(heights[0].size(), -1));
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                dfs(heights, grid, i, j, 1001);
            }
        }
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                cout << grid[i][j] << " ";
                if(grid[i][j] == 3) res.push_back({i, j});
                else if(max({grid[i][j], 
                            check(i+1, j, heights[i][j], grid, heights),
                            check(i-1, j, heights[i][j], grid, heights),
                            check(i, j+1, heights[i][j], grid, heights),
                            check(i, j-1, heights[i][j], grid, heights)}) == 3){
                                grid[i][j] = 3;
                                res.push_back({i, j});
                            }
            }
            cout << endl;
        }
        cout << endl;
        
        return res;
    }
};
