class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void usj(int x, int y, int j, int i, int s){
        int u = find(y*s+x);
        int v = find(i*s+j);
        if(u == v) return;
        if(rank[u] >= rank[v]){
            parent[v] = u;
            rank[u] += rank[v];
        }else{
            parent[u] = v;
            rank[v] += rank[u];
        }
    }

    bool check(int i, int j, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] == 'O') return true;
        return false;
    }

    void printBoard(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void solve(vector<vector<char>>& board) {
        printBoard(board);
        unordered_map<int, bool> isSurrounded;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                parent.push_back(i*board[0].size()+j);
                rank.push_back(1);
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    if(check(i+1, j, board)) usj(j, i, j, i+1, board[0].size());
                    if(check(i-1, j, board)) usj(j, i, j, i-1, board[0].size());
                    if(check(i, j+1, board)) usj(j, i, j+1, i, board[0].size());
                    if(check(i, j-1, board)) usj(j, i, j-1, i, board[0].size());
                    if(i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1){
                        isSurrounded[find(i*board[0].size()+j)] = false;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O' && 
                    isSurrounded.find(find(i*board[0].size()+j)) == isSurrounded.end()){
                    board[i][j] = 'X';
                }
            }
        }
        printBoard(board);
    }
};
