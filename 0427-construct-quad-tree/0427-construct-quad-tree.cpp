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
        auto [node, val] = build(grid, 0, 0, grid.size());
        if (node) return node;
        else return new Node(val, true);
    }
private:
    pair<Node*, int> build(vector<vector<int>>& grid, int i, int j, int size) {
        if (size == 1) return {nullptr, grid[i][j]};
        int newSize = size / 2;
        auto [topL, topL_val] = build(grid, i, j, newSize);
        auto [topR, topR_val] = build(grid, i, j + newSize, newSize);
        auto [botL, botL_val] = build(grid, i + newSize, j, newSize);
        auto [botR, botR_val] = build(grid, i + newSize, j + newSize, newSize);
        if (topL_val == topR_val && topR_val == botL_val && botL_val == botR_val && topL_val != -1) {
            return {nullptr, topL_val};
        } else {
            if (!topL) topL = new Node(topL_val, true);
            if (!topR) topR = new Node(topR_val, true);
            if (!botL) botL = new Node(botL_val, true);
            if (!botR) botR = new Node(botR_val, true);
            return {new Node(-1, false, topL, topR, botL, botR), -1};
        }
    }
};
/*
pair<Node*, int> Node* recursion (grid range)
    if the grid has only one element
        return element value
    find the center of the grid
    recursion(topleft)
    recursion(topright)
    recursion(bottomleft)
    recursion(bottomright)
    if 4 values are the same
        return value
    else
        create nodes for each recursion if it doesn't have
        create nodes for current grid
        return node, -1
*/