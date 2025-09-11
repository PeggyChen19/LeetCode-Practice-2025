/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) return nullptr;
        return build(grid, 0, 0, grid.size());
    }
private:
    Node* build(const vector<vector<int>>& grid, int i, int j, int size) {
        if (size == 1) return new Node(grid[i][j] == 1, true);
        int newSize = size / 2;
        Node* tl = build(grid, i, j, newSize);
        Node* tr = build(grid, i, j + newSize, newSize);
        Node* bl = build(grid, i + newSize, j, newSize);
        Node* br = build(grid, i + newSize, j + newSize, newSize);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
            // 4 children are leaves and have the same val -> collapse
            bool val = tl->val;
            delete tl; delete tr; delete bl; delete br;
            return new Node(val, true);
        } else {
            // create new node to connect children
            return new Node(true, false, tl, tr, bl, br);
        }
    }
};
/*
Node* recursion (grid range)
    if the grid has only one element
        return new node
    recursion(topleft)
    recursion(topright)
    recursion(bottomleft)
    recursion(bottomright)
    if 4 children are leaves and have the same val -> collapse
        delete children
        return new leaf
    else
        return new node
*/