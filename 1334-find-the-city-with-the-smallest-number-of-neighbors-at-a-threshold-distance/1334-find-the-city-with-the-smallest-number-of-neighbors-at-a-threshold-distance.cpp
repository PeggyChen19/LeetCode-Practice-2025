class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int node_ind = -1, global_min = INT_MAX;
        vector<vector<pair<int, int>>> graph(n); // adjacency list, src: {dst, weight}
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        for (int i = 0; i < n; i++) {
            int reachable = dijkstra(i, graph, distanceThreshold);
            if (reachable <= global_min) { // i is increasing -> always update to a bigger node
                global_min = reachable;
                node_ind = i;
            }
        }
        return node_ind;
    }
private:
    int dijkstra(int i, vector<vector<pair<int, int>>>& graph, int threshold) {
        int reachable = 0;
        int n = graph.size();
        vector<int> minDist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // weight, node
        minDist[i] = 0;
        minHeap.push({0, i});
        while (!minHeap.empty()) {
            auto [cur_w, cur] = minHeap.top();
            minHeap.pop();
            if (cur_w != minDist[cur]) continue; // outdated
            if (cur_w > threshold) break;
            if (i != cur) reachable++;
            for (auto [neighbor, weight] : graph[cur]) {
                int newWeight = cur_w + weight;
                if (newWeight < minDist[neighbor] && newWeight <= threshold) { // find better path
                    minDist[neighbor] = newWeight;
                    minHeap.push({newWeight, neighbor});
                }
            }
        }
        return reachable;
    }
};
/*
do the shortest path n times, if path > threshold -> break
There is no negative weight -> Dijkstra is faster

int node_val, global_min
for each node
        dijakstra(node)
        update node_ind, global_min

dijakstra(node)
    vector<int> min_dist
    priority_queue<pair<int, int>> minHeap // weight, node
    while (!heap.empty)
        go through all neighbors, try to find smaller distance (and distance should < threshold)
        update reachable
        push neighbor into heap
    calculate how many distance < threshold using min_dist

*/