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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &p : following[userId]){
            if(p.second == false) continue;
            for(int i = 0; i < posts[p.first].size(); i++){
                pq.push(posts[p.first][i]);
                if(pq.size() > 10) pq.pop();
            }
        }

        vector<int> res(pq.size());
        while(!pq.empty()){
            res[pq.size()-1] = pq.top().second;
            pq.pop();
        }
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
