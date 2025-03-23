class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent_list(numCourses);
        // build graph
        for (auto pre : prerequisites) {
            adjacent_list[pre[1]].push_back(pre[0]);
        }
        // check cycle using DFS
        vector<bool> visited(numCourses, false);
        vector<bool> same_path(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if(dfs_cycle_detect(adjacent_list, i, visited, same_path)) {
                return false; // has cycle -> can't finish course
            }
        }
        return true;
    }
private:
    bool dfs_cycle_detect(vector<vector<int>>& adjacent_list, int i, vector<bool>& visited, vector<bool>& same_path) {
        if (same_path[i]) {
            return true; // cycle
        }
        if (visited[i]) {
            return false; // ignore this visited node
        }
        visited[i] = true;
        same_path[i] = true;
        for (int n = 0; n < adjacent_list[i].size(); n++) {
            if (dfs_cycle_detect(adjacent_list, adjacent_list[i][n], visited, same_path)) {
                return true;
            }
        }
        same_path[i] = false;
        return false;
    }

};

/*
we can build a graph based on prerequistites
and then we can check if the graph contains cycle (DFS / BFS)
yes -> return false
no -> return true
this is the concept of topological ordering
*/