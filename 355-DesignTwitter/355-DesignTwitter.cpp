// Last updated: 7/18/2026, 2:04:48 PM
class Twitter {
private:
    int t;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        
        if (tweets.find(userId) != tweets.end() && !tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;
            pq.push({tweets[userId][i].first, tweets[userId][i].second, userId, i});
        }
        
        for (int fId : follows[userId]) {
            if (tweets.find(fId) != tweets.end() && !tweets[fId].empty()) {
                int i = tweets[fId].size() - 1;
                pq.push({tweets[fId][i].first, tweets[fId][i].second, fId, i});
            }
        }
        
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            auto curr = pq.top();
            pq.pop();
            
            ans.push_back(curr[1]);
            
            int uId = curr[2];
            int i = curr[3];
            
            if (i > 0) {
                pq.push({tweets[uId][i - 1].first, tweets[uId][i - 1].second, uId, i - 1});
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};