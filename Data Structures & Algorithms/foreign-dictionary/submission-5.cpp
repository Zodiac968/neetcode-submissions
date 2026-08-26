class Solution {
public:

    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adjList(26);
        vector<vector<bool>> exists(26, vector<bool>(26, false));
        unordered_map<char, int> indegree(26);
        int count = 0;
        if(words.size() == 1) return words[0];
        for(int i = 0; i < words.size()-1; i++){
            //find first differing character
            for(int j = 0; j < words[i].size(); j++){
                if(indegree.find(words[i][j]) == indegree.end()){
                    indegree[words[i][j]] = 0;
                    count++;
                }
            }
            for(int j = 0; j < words[i+1].size(); j++){
                if(indegree.find(words[i+1][j]) == indegree.end()){
                    indegree[words[i+1][j]] = 0;
                    count++;
                }
            }
            int j = 0;
            while(j < words[i].size() && j < words[i+1].size() && words[i][j] == words[i+1][j]){
                j++;
            }
            if(j == words[i+1].size() && j != words[i].size()) return "";
            if(j == words[i].size()) continue;
            if(exists[words[i][j] - 'a'][words[i+1][j] - 'a'] == false){
                adjList[words[i][j] - 'a'].push_back(words[i+1][j] - 'a');
                exists[words[i][j] - 'a'][words[i+1][j] - 'a'] = true;
                indegree[words[i+1][j]]++;
            }
        }

        queue<int> q;
        string result;
        for(int i = 0; i < adjList.size(); i++){
            if(indegree.find(i + 'a') == indegree.end()) continue;
            cout << char(i + 'a') << ": ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << char(adjList[i][j] + 'a') << " ";
            }
            cout << indegree[i + 'a'] << endl;
            if(indegree[i + 'a'] == 0) q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            result += char(i + 'a');
            for(int j = 0; j < adjList[i].size(); j++){
                if(--indegree[adjList[i][j] + 'a'] == 0){
                    q.push(adjList[i][j]);
                }
            }
        }
        if(result.size() < count) return "";
        return result;
    }
};
