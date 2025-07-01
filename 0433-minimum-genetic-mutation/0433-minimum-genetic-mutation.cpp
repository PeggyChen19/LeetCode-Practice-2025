class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        vector<bool> visited(n, false);
        queue<string> q;
        q.push(startGene);
        int steps = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                if (cur == endGene) return steps;
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && onlyOneMutation(cur, bank[j])) {
                        visited[j] = true;
                        q.push(bank[j]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
private:
    bool onlyOneMutation(string cur, string next) {
        int diffCount = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] != next[i]) {
                diffCount++;
                if (diffCount > 1) return false;
            }
        }
        return diffCount == 1;
    }
};
/*
BFS based solution, keep exploring what current genes can reach until endGene
create visited bool vector
create queue
q.push(start)
while !q.empty
    cur = q.front
    if cur == end return layer_number
    push the unvisited gene in bank that only requires one mutation from cur

Time: O(n) // every gene in bank only visits once
Space: O(n) // store all genes
*/