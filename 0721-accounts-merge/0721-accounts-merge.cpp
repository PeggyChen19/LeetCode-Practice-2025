class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> rank(n, 1);
        vector<int> parent(n);
        unordered_map<string, int> emails; // email: index
        for (int i = 0; i < n; i++) { // create disjoint sets & find duplications
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) { // skip name -> start from 1
                string newEmail = accounts[i][j];
                if (emails.count(newEmail)) { // duplicated -> union
                    unionSets(i, emails[newEmail], rank, parent);
                } else {
                    emails[newEmail] = i;
                }
            }
        }
        unordered_map<int, set<string>> merged; // roots of disjoint set: emails
        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            for (int j = 1; j < accounts[i].size(); j++) {
                merged[root].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> results;
        for (auto& iter : merged) {
            vector<string> content;
            content.push_back(accounts[iter.first][0]); // name
            for (auto& iter2 : merged[iter.first]) {
                content.push_back(iter2); // emails
            }
            results.push_back(content);
        }
        return results;
    }
private:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a) {
            return a;
        }
        parent[a] = find(parent[a], parent);
        return parent[a];
    }
    void unionSets(int a, int b, vector<int>& rank, vector<int>& parent) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB) {
            return;
        }
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rootB++;
        }
    }
};
/*
For an email appears in more than one account -> merge (must have the same name)
Emails of an account should be sorted

1. create disjoint sets for all indexes
2. create unordered_map<string, int> email: index
3. when encountering duplicated emails -> merge two disjoint set
4. create unordered_map<int, set> index(root of disjoint set): email set
5. transfer 4 to result
*/