class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent_list(numCourses);
        vector<int> indegree(numCourses, 0);
        // build graph
        for (auto pre : prerequisites) {
            adjacent_list[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        // check cycle using BFS
        queue<int> q;
        int topological_count = 0;
        for(int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            topological_count++;
            for (int neighbor : adjacent_list[cur]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return topological_count == numCourses;
    }
};

/*
we can build a graph based on prerequistites
and then we can check if the graph contains cycle (DFS / BFS)
yes -> return false
no -> return true
this is the concept of topological ordering
*/