class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> status(n, 0); // 0: unvisited, 1: visiting, 2: not-safe, 3: safe
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, status)) {
                result.push_back(i);
            }
        }
        return result;
    }
private:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& status) {
        if (status[i] == 1) { // cycle -> not safe
            status[i] == 2;
            return false;
        } else if (status[i] > 1) { // has have result
            return status[i] == 3;
        }
        status[i] = 1;
        for (int n : graph[i]) {
            if(!dfs(graph, n, status)) { // if at least one neighbor is not-safe
                status[i] = 2; // the cur not is not safe neither
                return false;
            }
        }
        status[i] = 3; // all neighbors are safe or it's the terminate node
        return true;
    }
};
/*
if the node is in a cycle -> not a safe node
use DFS to record
    if all nodes from this node are safe, this node is safe
    else, this node is not safe

          4 -> 5
          |
0 -> 1 -> 2 -> 3
     ^         |
     |---------|

*/