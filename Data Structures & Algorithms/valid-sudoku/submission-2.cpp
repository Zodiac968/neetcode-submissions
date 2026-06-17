class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Row
        vector<unordered_map<int, int>> freqr(9);
        vector<unordered_map<int, int>> freqc(9);
        vector<unordered_map<int, int>> sq(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(freqr[i][board[i][j] - '0'] == 0){
                        freqr[i][board[i][j] - '0']++;
                    }
                    else{ cout << "r" << endl; return false;}

                    int index = i / 3 + (j/3) * 3;
                    if(sq[index][board[i][j] - '0'] == 0)
                        sq[index][board[i][j] - '0']++;
                    else{ cout << "s" << endl; return false; }
                }
                if(board[j][i] != '.'){
                    cout << board[j][i] << " " << freqc[j][board[j][i] - '0'] << endl;
                    if(freqc[i][board[j][i] - '0'] == 0){
                        freqc[i][board[j][i] - '0']++;
                    }
                    else{cout << "c" << endl; return false;}
                }
            }
        }
        return true;
    }
};
