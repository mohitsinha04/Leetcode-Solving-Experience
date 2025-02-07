class Twitter {
private:
    unordered_map<int, set<int>> users;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timer;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer, tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto tweet:tweets[userId]){
            if(pq.size() < 10)
                pq.push({tweet.first, tweet.second});
            else if(pq.top().first < tweet.first){
                pq.pop();
                pq.push({tweet.first, tweet.second});
            }
        }

        for(auto followeeId:users[userId]){
            for(auto tweet:tweets[followeeId]){
                if(pq.size() < 10)
                    pq.push({tweet.first, tweet.second});
                else if(pq.top().first < tweet.first){
                    pq.pop();
                    pq.push({tweet.first, tweet.second});
                }
            }
        }

        vector<int> answer(pq.size());
        for(int i = answer.size()-1; i >= 0; i--){
            answer[i] = pq.top().second;
            pq.pop();
        }
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users[followerId].find(followeeId) != users[followerId].end())
            users[followerId].erase(followeeId);
    }
};