class Solution {
public:
    bool placeQueen(vector<string>& board, int x, int y, int n){
        for(int i = 0; i < n; i++){ //Horizontal & vertical
            if(board[y][i] == 'Q') return false;
            if(board[i][x] == 'Q') return false;
        }
        int i = 1;
        while(x+i < n && y-i >= 0){ //Diagonal ru
            if(board[y-i][x+i] == 'Q') return false;
            i++;
        }
        i = 1;
        while(x-i >= 0 && y-i >= 0){ //Diagonal lu
            if(board[y-i][x-i] == 'Q') return false;
            i++;
        }
        board[y][x] = 'Q';
        return true;
    }

    void findSol(vector<vector<string>>& res, vector<string>& base, int x, int y, int n, int curr){
        if(curr == n){
            res.push_back(base);
            return;
        }
        int i = y;
        int j = x;
        if(j >= n){
            j = 0;
            i++;
        } 
        while(i < n){
            while(j < n){
                if(base[i][j] == '.'){
                    bool result = placeQueen(base, j, i, n);
                    // cout << curr << " " << j << " " << i << endl;
                    // for(int i = 0; i < base.size(); i++){
                    //     cout << base[i] << endl;
                    // }
                    if(result) {
                        cout << endl;
                        findSol(res, base, j+1, i, n, curr+1);
                        base[i][j] = '.';
                    }
                }
                j++;
            }
            j = 0;
            i++;
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> base;
        for(int i = 0; i < n; i++){
            string row = "";
            for(int j = 0; j < n; j++){
                row += ".";
            }
            base.push_back(row);
        }
        findSol(res, base, 0, 0, n, 0);
        return res;
    }
};
