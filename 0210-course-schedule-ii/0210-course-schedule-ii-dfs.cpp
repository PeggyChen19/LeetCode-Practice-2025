class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) {
                continue;
            }
            if (hasCycle(i, graph, visited, onPath, result)) {
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    bool hasCycle(int course, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onPath, vector<int>& result) { 
        if (onPath[course]) return true; // detect cycle
        if (visited[course]) return false;
        visited[course] = true;
        onPath[course] = true;
        for (auto& neighbor : graph[course]) {
            if (hasCycle(neighbor, graph, visited, onPath, result)) {
                return true;
            }
        }
        onPath[course] = false; // recover
        result.push_back(course);
        return false;
    }
};
/*
[0, 1]: 1 must before 0 (1->0)
prerequisites actually represent a graph
build this graph based on adjacent list
we need to find the topological ordering and check if there is any cycle -> BFS / DFS
*/