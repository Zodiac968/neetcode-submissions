class Solution {
public:
    bool checkValid(string& a, string& b){
        bool isDiffering = false;
        for(int i = 0; i < a.size(); i++){
            if(!isDiffering && a[i] != b[i]){
                isDiffering = true;
                continue;
            }else if(a[i] != b[i]) return false;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> visitless = wordList;
        queue<string> q;
        q.push(beginWord);
        int count = 0;
        bool found = false;
        while(!q.empty() && !found){
            vector<string> currLevel;
            int size = q.size();
            while(size--){
                currLevel.push_back(q.front());
                q.pop();
            }
            count++;
            for(int i = 0; i < currLevel.size(); i++){
                string currWord = currLevel[i];
                if(currWord == endWord){
                    found = true;
                    break;
                }
                erase_if(visitless, [&](string& x){
                    if(checkValid(x, currWord)){
                        q.push(x);
                        cout << x << endl;
                        return true;
                    }
                    return false;
                });
            }
        }
        if(found) return count;
        else return 0;
    }
};
