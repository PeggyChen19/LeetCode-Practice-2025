class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int zeroReachAllCost = 0;
        queue<int> q;
        vector<bool> visited(n, false); 
        q.push(0);
        visited[0] = true;
        vector<vector<pair<int, int>>> graph(n);
        for (auto conn : connections) {
            graph[conn[0]].push_back({conn[1], 0}); // original direction
            graph[conn[1]].push_back({conn[0], 1}); // reversed direction
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto [neighbor, cost] : graph[cur]) {
                if (visited[neighbor]) continue;
                zeroReachAllCost += cost;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        return (n - 1) - zeroReachAllCost;
        // 0 reaches all nodes requires zeroReachAllCost
        // so, reversely, all nodes reach 0 requires (n-1) - zeroReachAllCost
    }
};
/*
topological order -> not work
- building topological order needs to create new edges, which is not allowed here
- this problem is not DAG

disjoint set -> not work
- disjoint set is undirected, but in this problem, direction matters

Target: make all nodes reach 0 -> reverse: 0 can reaches all nodes

n nodes & n - 1 edges -> a tree
-> when not considering directions, two node has exactly one road between each other

Greedy + Tree traversal (BFS)

create int zeroReachAllCost
create visited array
create adjacent list: vector<vector<pair<int, int>>> // pair0: the destination, pair1: the direction
push 0 into queue // start from zero
for edge[i, j] in edges
    adjacent[i].push_back{j, 0} // original direction
    adjacent[j].push_back{i, 1} // reversed direction

while q is not empty
    push all inbound unvisited edges into q & update zeroReachAllCost
    push all outbound unvisited edges into q
    q.pop()
return (n - 1) - zeroReachAllCost

// 0 reaches all nodes requires zeroReachAllCost
// so, reversely, all nodes reach 0 requires (n-1) - zeroReachAllCost

*/