class Twitter {
    unordered_map<int,unordered_set<int>>follows;
    vector<pair<int,int>>v;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int j=v.size()-1;
        int k=10;
        while(k && j>=0){
            int person=v[j].first;
            int tweet=v[j].second;
            if(person==userId || follows[userId].count(person)){
                ans.push_back(tweet);
                --k;
            }
            --j;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // follows[followeeId].insert(followerId);
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // follows[followeeId].erase(followerId);
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */