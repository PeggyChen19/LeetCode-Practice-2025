class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        traverse(root, prev);
    }

private:
    void traverse(TreeNode* node, TreeNode*& prev) {
        if (!node) return;
        traverse(node->right, prev);
        traverse(node->left, prev);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};
/*
preorder: root -> left -> right
limit: in-place

link all nodes via left and change all to right? hard to implement
improvement: "reverse" preorder: right -> left -> root, and use global pointer "prev"
1. recursively traverse (right -> left -> root)
2. cur->right = previous visited node
3. cur->left = nullptr
4. update prev
*/