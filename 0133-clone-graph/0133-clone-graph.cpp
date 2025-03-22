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
        queue<Node*> q;
        q.push(node);
        Node* copied_node = new Node(node->val);
        copies[node] = copied_node;
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* neighbor : cur->neighbors) {
                if (!copies.count(neighbor)) { // copied neighbor non-existed
                    Node* copied_neighbor = new Node(neighbor->val);
                    copies[neighbor] = copied_neighbor;
                    q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copied_node;
    }
};
/*
BFS go through all nodes
push root
create copied root
while !empty
    got the front (cur)
    go through all neighbors
        if neighbors not exists
            create with val
        record the neighbors of cur node
    push all neighbors

*/