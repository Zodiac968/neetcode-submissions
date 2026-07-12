class Solution {
public:
    struct Node {
        char c;
        bool isEnd;
        unordered_map<char, Node*> branch;
    };
    Node* root = nullptr;
    void buildTrie(string word){
        if(root == nullptr) root = new Node({'*', false});
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->branch.find(word[i]) == curr->branch.end()){
                Node* t = new Node({word[i], false});
                curr->branch[word[i]] = t;
                curr = t;
            }else{
                curr = curr->branch[word[i]];
            }
        }
        curr->isEnd = true;
    }


    void find(vector<vector<char>>& board, int x, int y, string& word, unordered_map<int, bool>& pairs,
            Node* curr, vector<string>& res){
        if(x >= board[0].size() || x < 0 || y >= board.size() || y < 0) return;
        if(pairs.find(y*board[0].size() + x) != pairs.end() && pairs[y*board[0].size() + x]) return;
        if(curr->branch.find(board[y][x]) != curr->branch.end()){
            curr = curr->branch[board[y][x]];
            word += board[y][x];
            //cout << word << endl;
            if(curr->isEnd){
                res.push_back(word);
                curr->isEnd = false;
            }
            pairs[y*board[0].size() + x] = true;
            find(board, x+1, y, word, pairs, curr, res);
            find(board, x-1, y, word, pairs, curr, res);
            find(board, x, y+1, word, pairs, curr, res);
            find(board, x, y-1, word, pairs, curr, res);
            word.pop_back();
            pairs[y*board[0].size() + x] = false;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            buildTrie(words[i]);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                string word;
                unordered_map<int, bool> pairs;
                find(board, j, i, word, pairs, root, res);
            }
        }
        return res;
    }
};
