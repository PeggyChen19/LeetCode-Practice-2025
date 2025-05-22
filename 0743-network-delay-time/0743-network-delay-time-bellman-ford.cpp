class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX), nextDist(n + 1, INT_MAX);
        dist[k] = 0;
        for (int i = 1; i < n; i++) { // loop n-1 times
            bool updated = false;
            nextDist = dist;
            for (auto& edge : times) {
                int src = edge[0], dst = edge[1], time = edge[2];
                if (dist[src] != INT_MAX && dist[src] +time < nextDist[dst]) {
                    nextDist[dst] = dist[src] +time;
                    updated = true;
                }
            }
            dist = nextDist;
            if (!updated) break;
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
/*
Weighted and directed graph to find minimum time -> shortest path -> Bellman-ford / Dijkstra
Bellman-Ford:
vector<int> weight(n, INT_MAX)
weight[k] = 0
loop n-1 times
    for all edges
        update weight
    early break: no changes in this round
check the largest weight
*/