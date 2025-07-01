class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> genes = {'A', 'C', 'G', 'T'};
        unordered_set<string> bankSet(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        int steps = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                if (cur == endGene) return steps;
                for (int i = 0; i < cur.size(); i++) {
                    char original = cur[i];
                    for (int j = 0; j < genes.size(); j++) {
                        if (original == genes[j]) continue;
                        cur[i] = genes[j]; // do mutation
                        if (bankSet.count(cur)) {
                            q.push(cur);
                            bankSet.erase(cur);
                        }
                        cur[i] = original; // undo mutation
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
/*
BFS based solution, keep exploring valid genes from current gene until reaching endGene
created unordered_set to record bank
create queue
q.push(start)
while !q.empty
    cur = q.front
    if cur == end return layer_number
    list all possible mutations
    check if each mutation is in bank or not

Time: O(n) // every gene in bank only visits once
Space: O(n) // store all genes
*/