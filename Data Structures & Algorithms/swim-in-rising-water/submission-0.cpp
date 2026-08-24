class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n, vector<int>(n, n*n));
        auto compare = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        decltype(compare)> pq(compare);
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int val = pq.top().first;
            pair<int, int> xy = pq.top().second;
            pq.pop();
            matrix[xy.first][xy.second] = val;
            int i = xy.first, j = xy.second;
            if(xy.first == n-1 && xy.second == n-1) return matrix[xy.first][xy.second];
            if(i - 1 >= 0 && matrix[i-1][j] > max(grid[i-1][j], val)) pq.push({max(grid[i-1][j], val), {i-1, j}}); //top 
            if(j + 1 < n && matrix[i][j+1] > max(grid[i][j+1], val)) pq.push({max(grid[i][j+1], val), {i, j+1}}); //right 
            if(i + 1 < n && matrix[i+1][j] > max(grid[i+1][j], val)) pq.push({max(grid[i+1][j], val), {i+1, j}}); //bottom
            if(j - 1 >= 0 && matrix[i][j-1] > max(grid[i][j-1], val)) pq.push({max(grid[i][j-1], val), {i, j-1}}); //left
        }
        return matrix[n-1][n-1];
    }
};
