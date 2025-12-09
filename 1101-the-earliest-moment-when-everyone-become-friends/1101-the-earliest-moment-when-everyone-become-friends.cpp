class UnionFind {
private:
    vector<int> parents;
    vector<int> rank;

public:
    UnionFind(int n) {
        parents.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {          // return root of x
        if (x != parents[x]) { // x is not root
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void unite(int x, int y) { // put x and y into same disjoint set
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return; // optional

        if (rank[rootX] > rank[rootY]) {
            parents[rootY] = rootX;
        } else if (rank[rootY] > rank[rootX]) {
            parents[rootX] = rootY;
        } else {
            parents[rootX] = rootY;
            rank[rootY]++;
        }
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int remain = n;
        sort(logs.begin(), logs.end()); // sort logs by timestamp
        UnionFind uf(n);
        for (auto log : logs) {
            int timestamp = log[0];
            int x = log[1];
            int y = log[2];

            if (uf.find(x) != uf.find(y)) { // x and y are not friends
                uf.unite(x, y);
                remain--;
            }
            if (remain == 1)
                return timestamp;
        }
        return -1;
    }
};

