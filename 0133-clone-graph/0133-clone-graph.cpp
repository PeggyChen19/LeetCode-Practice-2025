/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<Node*, Node*> copies; // original: copied
        Node* copied_node = new Node(node->val);
        copies[node] = copied_node;
        dfs(node, copies);
        return copied_node;
    }
private:
    void dfs(Node* node, unordered_map<Node*, Node*>& copies) {
        for (auto neighbor : node->neighbors) {
            if (!copies.count(neighbor)) { // copy non-existed
                Node* copied_neighbor = new Node(neighbor->val);
                copies[neighbor] = copied_neighbor;
                dfs(neighbor, copies); // go into the neighbor
            }
            (copies[node]->neighbors).push_back(copies[neighbor]);
        }
    }
};
/*
DFS
unorderd_map copies // original:copied
created copied root
dfs
    go through all neighbors
        if copied neighbor non-exist
            create new one
            dfs(neighbor)
        push_back copied_neighbor
*/