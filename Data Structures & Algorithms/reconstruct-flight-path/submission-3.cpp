class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& al, string curr, vector<string>& res){
        while(!al[curr].empty()){
            string destination = al[curr][al[curr].size()-1];
            al[curr].pop_back();
            dfs(al, destination, res);
        }
        res.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> adjList;
        for(int i = 0; i < tickets.size(); i++){
            adjList[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto& x : adjList){
            sort(x.second.begin(), x.second.end(), greater<string>());
        }
        string curr = "JFK";
        dfs(adjList, curr, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
