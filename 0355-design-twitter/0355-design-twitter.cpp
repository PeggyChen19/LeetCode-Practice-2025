class User {
public:
    vector<pair<int, int>> postList; // timestamp, tweetId
    set<int> followingSet;
    User() {}
};
class Twitter {
public:
    int timestamp;
    unordered_map<int, User*> userList;
    Twitter(): timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        checkUserExist(userId);
        userList[userId]->postList.push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> results;
        priority_queue<vector<int>> maxHeap; // timestamp, tweetId, userId, postListInd
        pushHeap(maxHeap, userId, userList[userId]->postList.size() - 1); // include user itself
        for (int f : userList[userId]->followingSet) {
            pushHeap(maxHeap, f, userList[f]->postList.size() - 1);
        }
        for (int i = 0; i < 10; i++) {
            if (!maxHeap.empty()) {
                results.push_back(maxHeap.top()[1]); // tweetId
                int uid = maxHeap.top()[2], ind = maxHeap.top()[3];
                maxHeap.pop();
                pushHeap(maxHeap, uid, ind - 1);
            }
        }
        return results;
    }
    
    void follow(int followerId, int followeeId) {
        checkUserExist(followerId);
        checkUserExist(followeeId);
        userList[followerId]->followingSet.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        checkUserExist(followerId);
        checkUserExist(followeeId);
        userList[followerId]->followingSet.erase(followeeId);
    }
private:
    void checkUserExist(int userId) {
        if (!userList.count(userId)) {
            userList[userId] = new User();
        }
    }
    void pushHeap(priority_queue<vector<int>>& maxHeap, int uid, int ind) {
        if (ind < 0) {
            return;
        }
        auto [timestamp, tweetId] = userList[uid]->postList[ind];
        maxHeap.push({timestamp, tweetId, uid, ind});
    }
};

/**
for posts sorted from newest to oledest -> stack / vector(with increasing timestamp)
but we need to filter posts based on the user followee list

every user have
1. a separate post vector with global increasing timestamp
2. a followee list -> set

post: O(1)
post vector push_back
global id increase

follow, unfollow: O(1)
insert / erase from set

getNews:
build max heap based on the newest post ids of all followees
for (i = 0; i < 10; i++)
    pop(post)
    push(post.user.next_newest_post)
Time Complexity: O(logF)

 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */