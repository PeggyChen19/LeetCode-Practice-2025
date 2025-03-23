class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int num_node = graph.size();
        vector<char> status(num_node, 'u'); // 'u': unvisited, v: visiting, n: not-safe, s: safe
        for (int i = 0; i < num_node; i++) {
            dfs(graph, i, status);
        }
        for (int i = 0; i < num_node; i++) {
            if (status[i] == 's') {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    bool dfs(vector<vector<int>>& graph, int i, vector<char>& status) {
        if (status[i] == 'v') { // cycle -> not safe
            status[i] == 'n';
            return false;
        } else if (status[i] == 'n') {
            return false;
        } else if (status[i] == 's') {
            return true;
        }
        status[i] = 'v';
        for (int n : graph[i]) {
            if(!dfs(graph, n, status)) { // if at least one neighbor is not-safe
                status[i] = 'n'; // the cur not is not safe neither
                return false;
            }
        }
        status[i] = 's'; // all neighbors are safe or it's the terminate node
        return true;
    }
};
/*
if the node is in a cycle -> not a safe node
but for a node starts from a node in cycle but reaches terminate node can be a safe node
use DFS to record
    if all nodes from this node are safe, this node is safe
    else, this node is not safe

          4 -> 5
          |
0 -> 1 -> 2 -> 3
     ^         |
     |---------|

*/