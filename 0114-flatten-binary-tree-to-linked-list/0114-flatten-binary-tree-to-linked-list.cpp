class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
/*
preorder: root -> left -> right
limit: in-place

link all nodes via left and change all to right? hard to implement
improvement: "reverse" preorder: right -> left -> root
1. recursively traverse (right->left->root)
2. cur->right = previous visited node
3. cur->left = nullptr
4. update prev
*/