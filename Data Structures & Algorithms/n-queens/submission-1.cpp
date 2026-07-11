class Solution {
public:
    unordered_map<int, bool> col;
    unordered_map<int, bool> rD;
    unordered_map<int, bool> lD;
    bool placeQueen(vector<string>& board, int x, int y, int n){
        if(col.find(x) != col.end() && col[x] == true) return false;
        if(rD.find((x-y)) != rD.end() && rD[(x-y)] == true) return false;
        if(lD.find((x+y)) != lD.end() && lD[(x+y)] == true) return false;
        col[x] = true;
        //0+3
        //0+2, 1+3 
        //0+1, 1+2, 2+3
        //0+0, 1+1, 2+2, 3+3
        //1+0, 2+1, 3+2
        //2+0, 3+1
        //3+0
        rD[(x-y)] = true;
        lD[x+y] = true;
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
        while(j < n){
            if(base[i][j] == '.'){
                bool result = placeQueen(base, j, i, n);
                if(result) {
                    findSol(res, base, 0, i+1, n, curr+1);
                    col[j] = false;
                    rD[j-i] = false;
                    lD[j+i] = false;
                    base[i][j] = '.';
                }
            }
            j++;
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
