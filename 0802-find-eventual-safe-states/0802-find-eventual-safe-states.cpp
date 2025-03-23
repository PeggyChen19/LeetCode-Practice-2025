class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int num_node = graph.size();
        vector<bool> ans(num_node, false);
        vector<vector<int>> reverse_graph(num_node);
        vector<int> indegree(num_node, 0);
        for (int i = 0; i < num_node; i++) {
            for (int n : graph[i]) {
                reverse_graph[n].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < num_node; i++) {
            if (indegree[i] == 0) { // terminate nodes
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans[cur] = true;
            for (int n : reverse_graph[cur]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < num_node; i++) {
            if(ans[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
/*
if the node is in a cycle -> not a safe node
but for a node starts from a node in cycle but reaches terminate node can be a safe node
use BFS:
find the nodes which no outcoming node -> terminate node
push into queue
while
    mark front node as safe and remove its incoming edge
    push new nodes which have not outcoming node
like topological sort reversed version

          4 -> 5
          |
0 -> 1 -> 2 -> 3
     ^         |
     |---------|

*/