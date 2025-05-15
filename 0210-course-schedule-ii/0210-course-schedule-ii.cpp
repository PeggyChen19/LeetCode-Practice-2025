class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto& neighbor : graph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return (result.size() == numCourses) ? result : vector<int>{};
    }
};
/*
[0, 1]: 1 must before 0 (1->0)
prerequisites actually represent a graph
build this graph based on adjancent list
we need to find the topological ordering and check if there is any cycle -> BFS
*/
