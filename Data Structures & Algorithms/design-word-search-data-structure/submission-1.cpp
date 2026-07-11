class WordDictionary {
public:
    struct Node{
        char c;
        bool isEnd = false;
        unordered_map<char, Node*> branch;
    };
    Node* root;
    WordDictionary() {
        root = new Node({'*', false});
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->branch.find(word[i]) == curr->branch.end()){
                Node *t = new Node({word[i], false});
                curr->branch[word[i]] = t;
                curr = t;
            }else{
                curr = curr->branch[word[i]];
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word, Node* startPoint = nullptr) {
        Node* curr;
        if(startPoint == nullptr) curr = root;
        else curr = startPoint;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                bool res = false;
                for(auto &p : curr->branch){
                    res |= search(word.substr(i+1, word.size()-1-i), p.second);
                }
                if(!res) return false;
                else return true;
            }
            if(curr->branch.find(word[i]) == curr->branch.end()) return false;
            curr = curr->branch[word[i]];
        }
        if(curr->isEnd) return true;
        return false;
    }
};
