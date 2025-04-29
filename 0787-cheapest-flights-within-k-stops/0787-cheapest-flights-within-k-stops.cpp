class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n); // src: dst, cost
        for (auto flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, INT_MAX); // the stop of lowest cost
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap; // cost, stop, node
        min_heap.push({0, 0, src});
        while (!min_heap.empty()) {
            auto [cost, stop, node] = min_heap.top();
            min_heap.pop();
            if (node == dst) return cost;
            if (stop > k) continue;
            if (stop >= dist[node]) continue; // top() has relative higher cost and dist -> not possible to be a better path
            dist[node] = stop; // update stop
            for (auto [neighbor, weight] : graph[node]) {
                min_heap.push({cost + weight, stop+1, neighbor});
            }
        }
        return -1;
    }
};
/*
No negative weight -> Dijsktra
*/