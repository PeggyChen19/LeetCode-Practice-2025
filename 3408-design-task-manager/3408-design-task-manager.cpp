class TaskManager {
private:
    struct CustomCompare {
        bool operator ()(const vector<int>& vec1, const vector<int>& vec2) const {
            if (vec1[2] == vec2[2]) return vec1[1] > vec2[1];
            else return vec1[2] > vec2[2];
        }
    };

public:
    set<vector<int>, CustomCompare> priority_order; //userId, taskId, priority
    unordered_map<int, set<vector<int>, CustomCompare>::iterator> iterator_map; // taskId -> iterator

    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        auto iter = priority_order.insert({userId, taskId, priority}).first;
        iterator_map[taskId] = iter;
    }
    
    void edit(int taskId, int newPriority) {
        auto iter = iterator_map[taskId];
        int userId = (*iter)[0];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        auto iter = iterator_map[taskId];
        priority_order.erase(iter);
        iterator_map.erase(taskId);
    }
    
    int execTop() {
        if (priority_order.empty()) return -1;
        auto iter = priority_order.begin();
        int userId = (*iter)[0];
        int taskId = (*iter)[1];
        rmv(taskId);
        return userId;
    }
};

/*
add & execTop -> add & pop the highest priority quickly 
edit & remove -> find the task quickly & remove from priority_queue

data structure
Main DS: store userId, taskId, priority
- priroity_queue -> can only get the top val -> not work
- map
    add & execTop: O(logn)
    edit & remove: O(n) -> need iterate to find
    map<vector<int>> // userId, taskId, priority

Helper DS:
unordered_map<int, iterator> // taskId, map iterator

map self-defined compare function
    compare priority (bigger first) -> taskId (bigger first)
 */