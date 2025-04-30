class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<int> cost(n, INT_MAX), tmp(n, INT_MAX); // node: cost
		cost[src] = 0;
		for (int i = 0; i <= k; i++) { // k stops (except src & dst) -> k+1 edges from src to dst
			bool changed = false;
			tmp = cost;
			for (auto f : flights) {
				if(cost[f[0]] != INT_MAX && cost[f[0]] + f[2] < tmp[f[1]]) {
					tmp[f[1]] = cost[f[0]] + f[2];
					changed = true;
				}
			}
			swap(cost, tmp);
			if (!changed) break;
		}
		return cost[dst] == INT_MAX ? -1 : cost[dst];
	}
};
/*
Bellman-ford
vector<int> cost // node: cost
cost[src] = 0

for i = 0; i <= k; i++
	bool changed = false
	for (f in flights)
		if f.src + f.cost < cost[dst]
			update cost
			changed = true
	if !changed
		return
return cost[dst]
*/