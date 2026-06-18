class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> freqr;
        unordered_map<int, int> freqc;
        vector<unordered_map<int, int>> freqS(9);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.' && freqr.find(board[i][j]) != freqr.end()) return false;
                else freqr.insert({board[i][j], 1});
                cout << "hello" << endl;
                if(board[j][i] != '.' && freqc.find(board[j][i]) != freqc.end()) return false;
                else freqc.insert({board[j][i], 1});
                
                int s = (i / 3) * 3 + (j / 3);
                cout << s << endl;
                if(board[i][j] != '.' && freqS[s].find(board[i][j]) != freqS[s].end()) return false;
                else freqS[s].insert({board[i][j], 1});
            }
            freqr.clear();
            freqc.clear();
        }
        return true;
    }
};
