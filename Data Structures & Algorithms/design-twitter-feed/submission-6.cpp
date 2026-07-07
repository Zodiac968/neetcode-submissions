class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_map<int, bool>> following;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        cout << "Posted : " << tweetId << " at " << time << endl;
        posts[userId].push_back({time++, tweetId});
        following[userId][userId] = true;
    }
    
    vector<int> getNewsFeed(int userId) {
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        unordered_map<int, int> index;
        while(res.size() < 10){
            int over = 0;
            int max = -1;
            int maxp = -1;
            for(auto &p : following[userId]){
                if(p.second == false) {
                    over++;
                    continue;
                }
                if(index.find(p.first) == index.end()) index[p.first] = posts[p.first].size()-1;
                if(index[p.first] < 0) {
                    over++;
                    continue;
                }
                if(max < posts[p.first][index[p.first]].second){
                    max = posts[p.first][index[p.first]].second;
                    maxp = p.first;
                }
            }
            index[maxp]--;
            if(max != -1)
                res.push_back(max);
            if(over == following[userId].size()) break;
        }

        // vector<int> res(pq.size());
        // while(!pq.empty()){
        //     res[pq.size()-1] = pq.top();
        //     pq.pop();
        // }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId) != following[followerId].end()
         || following[followerId][followeeId] == false){
            following[followerId][followeeId] = true;
        }
        following[followerId][followerId] = true;
        following[followeeId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) following[followerId][followeeId] = false;
    }
};
