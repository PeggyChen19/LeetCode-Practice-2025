class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        unordered_map<string, vector<pair<string, double>>> adjacent;
        for (int i = 0; i < equations.size(); i++) {
            adjacent[equations[i][0]].push_back({equations[i][1], values[i]});
            adjacent[equations[i][1]].push_back({equations[i][0], (1 / values[i])});
        }
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            if (!adjacent.count(queries[i][0]) || !adjacent.count(queries[i][1])) result.push_back(-1.0);
            else if (queries[i][0] == queries[i][1]) result.push_back(1.0);
            else {
                double ans = -1.0;
                queue<pair<string, double>> q;
                q.push({queries[i][0], 1});
                visited.insert(queries[i][0]);
                while (!q.empty()) {
                    auto [n, w] = q.front();
                    q.pop();
                    for (auto& [neighbor, weight] : adjacent[n]) {
                        if (!visited.count(neighbor)) {
                            q.push({neighbor, w * weight});
                            visited.insert(neighbor);
                            if (neighbor == queries[i][1]) {
                                ans = w * weight;
                                break;
                            }
                        }
                    }
                }
                result.push_back(ans);
            }
        }
        return result;
    }
};

/*
looks like a math question, but we can solve it in a programming way!
given
1. "pairwise" relations between symbols
2. a new relation can be derived from existing multiple relations
--> GRAPH!
symbols -> nodes
relations -> weights
A/B * B/C to eliminate B -> a path from A to C

1. Build a graph (adjacent list): A -> B (val) & B -> A (1/val)
2. Create a visited list
3. BFS
*/