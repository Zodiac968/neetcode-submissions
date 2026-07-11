class PrefixTree {
public:
    struct TrieNode{
        char c;
        bool isEnd = false;
        unordered_map<char, TrieNode*> branches;
    };
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode({'*', false});
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->branches.find(word[i]) == curr->branches.end()){
                TrieNode *t = new TrieNode({word[i], false});
                curr->branches[word[i]] = t;
                curr = t;
            }else{
                curr = curr->branches[word[i]];
            }
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->branches.find(word[i]) == curr->branches.end()) return false;
            curr = curr->branches[word[i]];
        }
        if(curr->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            if(curr->branches.find(prefix[i]) == curr->branches.end()) return false;
            curr = curr->branches[prefix[i]];
        }
        return true;
    }
};
