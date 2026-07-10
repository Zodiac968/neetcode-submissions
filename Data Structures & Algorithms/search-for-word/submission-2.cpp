class Solution {
public:
    bool traverse(vector<vector<char>>& board, string& word, int x, int y, int s, 
    vector<pair<int, int>>& path){
        if(s == word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        for(auto &p : path){
            if(p.first == x && p.second == y) return false;
        }
        if(word[s] == board[x][y]){
            path.push_back({x, y});
            bool a = traverse(board, word, x+1, y, s+1, path);
            bool b = traverse(board, word, x-1, y, s+1, path);
            bool c = traverse(board, word, x, y+1, s+1, path);
            bool d = traverse(board, word, x, y-1, s+1, path);
            path.pop_back();
            return a || b || c || d;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> path;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    bool a = traverse(board, word, i, j, 0, path);
                    if(a) return true;
                }
            }
        }
        return false;
    }
};
